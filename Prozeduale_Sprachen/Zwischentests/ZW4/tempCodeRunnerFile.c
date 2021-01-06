#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum msgtag
{
  NoTag = 0,
  Important,
  Work,
  Personal,
  ToDo,
  Later
} msgtag;

typedef struct MsgID
{
  char *id;
} MsgID;

typedef struct MsgDetails
{
  char *id;
  msgtag tag;
  int year;
  int month;
  int day;
} MsgDetails;

typedef struct Node
{
  void *item;
  struct Node *next;
} Node;

MsgDetails *read_data()
{
  MsgDetails *new_message = malloc(sizeof(MsgDetails));
  MsgDetails _new_message;
  char *id = malloc(sizeof(char) * 40);
  int tag;
  printf("\nenter msg metadata (tag,year,month,day,id): ");

  scanf("%d,%d,%d,%d,%s", &tag, &_new_message.year, &_new_message.month, &_new_message.day, id);
  new_message->tag = tag;
  new_message->month = _new_message.month;
  new_message->day = _new_message.day;
  new_message->year = _new_message.year;
  new_message->id = id;
  return new_message;
}

Node *addMsgDetails(Node *database, MsgDetails *msg)
{
  Node *traveler = database;
  while (traveler->next != NULL)
    traveler = traveler->next;
  Node *next_item = malloc(sizeof(Node));
  next_item->item = (MsgDetails *)msg;
  next_item->next = NULL;
  traveler->next = next_item;

  return database;
}

void create_new_entry(Node *database)
{
  MsgDetails *new_entry = read_data();
  if (database->item == NULL)
  {
    database->item = (MsgDetails *)new_entry;
    database->next = NULL;
  }
  else
  {
    database = addMsgDetails(database, new_entry);
  }
}
MsgID *create_new_id(MsgDetails *data)
{
  MsgID *new_id = malloc(sizeof(MsgID));
  char *id = malloc(sizeof(char) * 40);
  strcpy(id, data->id);
  new_id->id = id;
  return new_id;
}

Node *freeMsgDetails(Node *database)
{
  Node *traveler = database;
  Node *next_traveler;
  while (traveler != NULL)
  {
    next_traveler = traveler->next;
    free(((MsgDetails *)(traveler->item))->id);
    free(traveler->item);
    free(traveler);
    traveler = next_traveler;
  }

  return NULL;
}

Node *filterList(Node *database, int (*cmp)(int, MsgDetails *), int cmp_val, int return_of_cmp)
{
  Node *traveler = database;
  int count = 0;
  Node *new_list = malloc(sizeof(Node));
  new_list->item = NULL;
  new_list->next = NULL;
  while (traveler != NULL)
  {

    MsgDetails *entry = (MsgDetails *)traveler->item;
    //New_id->id = ((MsgDetails *) traveler->item)->id;

    if (cmp(cmp_val, entry) == return_of_cmp)
    {
      if (count == 0)
      {
        MsgID *new_id = create_new_id(entry);
        new_list->item = (MsgID *)new_id;
      }
      else
      {
        Node *new_list_entry = malloc(sizeof(Node));
        MsgID *new_id = create_new_id(entry);
        new_list_entry->item = (MsgID *)new_id;
        new_list_entry->next = new_list;
        new_list = new_list_entry;
      }
      count++;
    }
    traveler = traveler->next;
  }
  return new_list;
}

int matchTag(int tag, MsgDetails *msg)
{
  if (tag == msg->tag)
    return 1;
  else
  {
    return -1;
  }
}

int cmpYear(int year, MsgDetails *msg)
{
  if (year < msg->year)
    return -1;
  else if (year == msg->year)
    return 0;
  else
    return 1;
}
int cmpdate(int date, MsgDetails *msg)
{
  /*int year = date/10000;
  int month = (date/100)%100;
  int days = date %100;
  */
  int _date = msg->year * 10000 + msg->month * 100 + msg->day;
  if (date < _date)
    return -1;
  else if (date == _date)
    return 0;
  else
    return 1;
}

void print_list(Node *database)
{
  Node *traveler = database;
  MsgDetails *entry;
  while (traveler != NULL)
  {
    entry = (MsgDetails *)traveler->item;
    printf("\nID: %s", entry->id);
    printf("\n  %04d-%02d-%02d Tag: %d", entry->year, entry->month, entry->day, entry->tag);
    traveler = traveler->next;
  }
}

void print_id_list(Node *id_list)
{
  Node *traveler = id_list;
  while (traveler != NULL)
  {
    printf("\nID: %s", ((MsgID *)(traveler->item))->id);
    traveler = traveler->next;
  }
}

Node *reverseList(Node *database)
{
  Node *traveler = database;
  Node *nextform_traveler = database;
  Node *prev_traveler = database;
  int count = 0;
  // 7->6->5->NULL
  if (database == NULL || database->next == NULL)
    return database;
  else
  {
    while (nextform_traveler != NULL)
    {
      //NULL<-7<-6<-5
      if (count == 0)
      {
        nextform_traveler = traveler->next;
        traveler->next = NULL;
        prev_traveler = traveler;
        traveler = nextform_traveler;
      }
      else
      {
        nextform_traveler = traveler->next;
        traveler->next = prev_traveler;
        prev_traveler = traveler;
        traveler = nextform_traveler;
      }
      count++;
    }
    return prev_traveler;
  }

  return NULL;
}

Node *freeMsgIDs(Node *id_list)
{
  Node *traveler = id_list;
  Node *next_traveler = {0};
  while (traveler != NULL)
  {
    next_traveler = traveler->next;
    free(((MsgID *)(traveler->item))->id);
    free(traveler->item);
    free(traveler);

    traveler = next_traveler;
  }
  return NULL;
}

int main()
{
  Node *db = malloc(sizeof(Node));
  Node *id_list = NULL;
  db->item = NULL;
  db->next = NULL;
  char action = ' ';
  int date;
  int year;
  int tag;
  printf("\nMsgDB -- Testprogramm");
  while (42)
  {
    printf("\ncmd: ");
    scanf(" %c", &action);
    switch (action)
    {
    case 'r':
      create_new_entry(db);
      break;
    case 'R':
      db = reverseList(db);
      break;
    case 'p':
      print_list(db);
      break;
    case 't':
      printf("\nwhich tag (0-5)?");
      scanf("%d", &tag);
      id_list = filterList(db, &matchTag, tag, 1);
      print_id_list(id_list);
      id_list = freeMsgIDs(id_list);
      break;
    case 'y':
      printf("\nwhich year?");
      scanf("%d", &year);
      id_list = filterList(db, &cmpYear, year, 1);
      print_id_list(id_list);
      id_list = freeMsgIDs(id_list);
      break;
    case 'd':
      printf("\nwhich date (YYYYMMDD)?");
      scanf("%07d", &date);
      id_list = filterList(db, &cmpdate, date, 1);
      print_id_list(id_list);
      id_list = freeMsgIDs(id_list);
      break;
    case 'e':
      printf("\nwhich date (YYYYMMDD)?");
      scanf("%07d", &date);
      id_list = filterList(db, &cmpdate, date, 0);
      print_id_list(id_list);
      id_list = freeMsgIDs(id_list);
      break;
    case 'q':
      db = freeMsgDetails(db);
      return 0;
      break;
    }
  }
}