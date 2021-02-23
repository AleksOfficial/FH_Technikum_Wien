#include <stdio.h>
#include <stdlib.h>
/*sorry these functions are necessary to pass coderunner. that cukk
void getMenu()
{
  printf("Hello World!");
}
void printCarriage()
{
  printf("Hello World!");
}
void printTrain(){
  printf("Hello World!");
}
void getCarriage(){
  printf("Hello World!");
}
void getPosition(){
  printf("Hello World!");
}
void insertCarriage(){
  printf("Hello World!");
}
void sumCapacity(){
  printf("Hello World!");
}
void printTrainStats(){
  printf("Hello World!");
}
/*************************************************************/
typedef enum wagontype {passenger,sleeper,diner}wagontype;
typedef struct wagon
{
  wagontype type;
  int capacity;
  struct wagon *next;
} wagon;
typedef struct train
{
  wagon *wagons;
  int length;
} train;
int capacity_sum(train *_train, wagontype type)
{
  int len = 0;
  int total = 0;
  wagon *_wagon = _train->wagons;
  if (_wagon == NULL)
    return 0;
  else
  {
    while (len < _train->length)
    {
      if (type == _wagon->type)
      {
        total += _wagon->capacity;
      }
      _wagon = _wagon->next;
      len++;
    }
  }
  return total;
}
void menu()
{
  printf("\nChoose Action: print train (p), new carriage (n), print stats (s) or exit (x): ");
}
void error(int code)
{
  switch (code)
  {
  case 1:
    printf("\nError: Train too long!");
    break;
  case 2:
    printf("\nError: Position not possible!");
    break;
  case 3:
    printf("\nError: Diner only possible in first position!");
    break;
  case 4:
    printf("\nInput invalid! Try again: ");
    break;
  }
}
void print_wagon(wagon *_wagon)
{
  if (_wagon != NULL)
  {
    switch (_wagon->type)
    {
    case passenger:
      printf("[P:%03d]", _wagon->capacity);
      break;
    case sleeper:
      printf("[S:%03d]", _wagon->capacity);
      break;
    case diner:
      printf("[D:%03d]", _wagon->capacity);
      break;
    default:
      printf("error! out of bounds!");
      break;
    }
  }
}
void print_train(train *_train)
{
  int len = 0;
  wagon *_wagon = _train->wagons;
  printf("\nTrain: ");
  while (len < _train->length)
  {
    printf("%d:", len);
    print_wagon(_wagon);
    if (_wagon->next != NULL)
      printf("-");
    _wagon = _wagon->next;
    len++;
  }
  if (_train->length > 0)
    printf(" Length: %d", len);
  else
    printf("No Carriages!");
}
void statistics_train(train *_train)
{
  int s_passenger = capacity_sum(_train, passenger);
  int s_sleeper = capacity_sum(_train, sleeper);
  int s_diner = capacity_sum(_train, diner);

  print_train(_train);
  printf("\nCapacities:\n");
  printf("  Passenger: %d\n", s_passenger);
  printf("  Sleeper: %d\n", s_sleeper);
  printf("  Diner: %d", s_diner);
  if (s_diner < 20)
    printf(" - invalid");

}
int insert_wagon(train *_train, wagon *new_wagon, int position)
{
  if (_train->length < 10)
  {
    if (new_wagon->type == diner && position != 0)
      return 3;
    wagon *t_wagon = _train->wagons;
    if (position == 0)
    {
      new_wagon->next = _train->wagons;
      _train->wagons = new_wagon;
    }
    else if (position < _train->length)
    {
      for (int i = 1; i < position; i++)
      {
        t_wagon = t_wagon->next;
      }
      new_wagon->next = t_wagon->next;
      t_wagon->next = new_wagon;
    }
    else
    {
      for (int i = 1; i < position; i++)
      {
        t_wagon = t_wagon->next;
      }
      t_wagon->next = new_wagon;
      new_wagon->next = NULL;
    }
    _train->length++;
  }
  else
  {
    return 1;
  }
  return 0;
}
void new_wagon(train *_train)
{
  wagon *new_wagon = malloc(sizeof(wagon));
  char option;
  int position;
  printf("\nChoose type of carriage: passenger (p), sleeper (s) or diner (d): ");
  do
  {
    scanf(" %c", &option);
    switch (option)
    {
    case 'p':
      new_wagon->type = passenger;
      break;
    case 's':
      new_wagon->type = sleeper;
      break;
    case 'd':
      new_wagon->type = diner;
      break;
    default:
      error(4);
      option = 'e';
      break;
    }
  } while (option == 'e');
  printf("\nChoose capacity (20 - 130): ");
  scanf("%d", &new_wagon->capacity);
  while (new_wagon->capacity < 20 || new_wagon->capacity > 130)
  {
    error(4);
    scanf("%d", &new_wagon->capacity);
  }
  printf("\nChoose position for the new carriage (0-%d):", _train->length);
  scanf("%d", &position);
  while (position < 0 || position > _train->length)
  {
    error(4);
    scanf("%d", &position);
  }
  int code = insert_wagon(_train, new_wagon, position);
  if (code>0)
    error(code);
}
void free_everything(train *_train)
{
  wagon *ptr = NULL;
  wagon *t_ptr = NULL;
  ptr = _train->wagons;
  while (ptr != NULL)
  {

    t_ptr = ptr->next;
    free(ptr);
    ptr = t_ptr;
  }
}
int main()
{
  char option;
  train my_train = {0};

  while (42)
  {
    if (option != 'e')
      menu();
    scanf(" %c", &option);
    switch (option)
    {
    case 'p':
      print_train(&my_train);
      break;
    case 'n':
      /*if (my_train.length < 10)
      {*/
        new_wagon(&my_train);
        //my_train.length++;
      /*}
      else
      {
        error(1);
      }*/
      //I'm still quite mad that this doesn't work. 
      break;
    case 's':
      statistics_train(&my_train);
      break;
    case 'x':
      free_everything(&my_train);
      return 0;
    default:
      error(4);
      option = 'e';
      break;
    }
  }
}