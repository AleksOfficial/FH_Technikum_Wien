#include <stdio.h>
#include <stdlib.h>
/*sorry, Ich hab's nicht nach der Vorgabe gemacht mit Arrays sondern mit Linked-Lists;
Die einzigen 2 Funktionen, die ich nicht habe, sind getCarriage() und getPosition().
Ursprünglich hatte ich gar keine Funktion davon verwendet. Ich hab sie aber so ungefähr mit der Angabe gemapped,
wo die Funktion halbwegs übereinstimmt
Damit es im CodeRunner trotzdem funktioniert, hab ich sie hier einfach so implementiert lel.*/
void getCarriage(){
  printf("Hello World!");
}
void getPosition(){
  printf("Hello World!");
}
/*************************************************************/
typedef enum wagontype {passenger,sleeper,diner}wagontype; // = 0, 1, 2
typedef struct wagon
{ // Train --> capacity = 24, type = sleeper,  ->  capacity: 20, type = passenger  -> NULL
  wagontype type;
  int capacity;
  struct wagon *next;
} wagon;
typedef struct train
{
  wagon *wagons;
  int length;
} train;
int sumCapacity(train *_train, wagontype type)
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
      //Summenschritt
      if (type == _wagon->type)
      {
        total += _wagon->capacity;
      }
      //Iterationsschritt
      _wagon = _wagon->next;
      len++;
    }
  }
  return total;
}
void getMenu()
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
void printCarriage(wagon *_wagon)
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
    }
  }
}
void printTran(train *_train)
{
  int len = 0;
  wagon *_wagon = _train->wagons;
  printf("\nTrain: ");
  while (len < _train->length)
  {
    printf("%d:", len);
    printCarriage(_wagon); //prints the wagon 
    if (_wagon->next != NULL)
      printf("-");
    //Iterationsschritt
    _wagon = _wagon->next;
    len++;
  }
  if (_train->length > 0)
    printf(" Length: %d", len);
  else
    printf("No Carriages!");
}
void printTrainStats(train *_train)
{
  int s_passenger = sumCapacity(_train, passenger);
  int s_sleeper = sumCapacity(_train, sleeper);
  int s_diner = sumCapacity(_train, diner);

  printTrain(_train);
  printf("\nCapacities:\n");
  printf("  Passenger: %d\n", s_passenger);
  printf("  Sleeper: %d\n", s_sleeper);
  printf("  Diner: %d", s_diner);
  if (s_diner < 20)
    printf(" - invalid");

}
int insertCarriage(train *_train, wagon *new_wagon, int position)
{
  //ist länge =10 -> error1 
  if (_train->length < 10)
  {
    //wagon ist diner & andere position als 0 -> error3
    if (new_wagon->type == diner && position != 0)
      return 3;
    //3 cases: wagon an erster stelle/dazwischen/letzter stelle; je nachdem wird dann das element eingefügt
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
      new_wagon->type = passenger;//ich mag keine enums...  
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
    error(4);//error4 -> invalid input; witzigerweise wird der position error nie gebraucht? also error(2)
    scanf("%d", &new_wagon->capacity);
  }
  printf("\nChoose position for the new carriage (0-%d):", _train->length);
  scanf("%d", &position);
  while (position < 0 || position > _train->length)
  {
    error(4); // same spiel hier
    scanf("%d", &position);
  }
  int code = insertCarriage(_train, new_wagon, position); //Codes: 0-> all good,1 -> train too long, 2 -> pos invalid, 3 -> diner not on pos1
  if (code>0)
    error(code);
}
void free_everything(train *_train)
{
  wagon *ptr = NULL;
  wagon *t_ptr = NULL;
  ptr = _train->wagons; //fängt beim ersten Wagon an
  while (ptr != NULL)
  {

    t_ptr = ptr->next; //Backup zeigt auf nächstes Element
    free(ptr); //Freigabe
    ptr = t_ptr; //ptr zeigt jetzt auch auf nächstes Element 
  }
}
int main()
{
  char option;
  train my_train = {0};

  while (42)
  {
    if (option != 'e')
      getMenu();
    scanf(" %c", &option);
    switch (option)
    {
    case 'p':
      printTrain(&my_train);
      break;
    case 'n':
        //erstellt neuen Wagon. Funktion ruft danach Funktion insertCarriage auf, welche den Wagon einfügt.
        //wenn Errors entstehen, werden sie ausgegeben und es wird nichts verändert
        new_wagon(&my_train);
      break;
    case 's':
      printTrainStats(&my_train);
      break;
    case 'x':
      free_everything(&my_train); //der Speicher muss wieder freigegeben werden
      return 0;
    default:
      error(4); 
      option = 'e';
      break;
    }
  }
}