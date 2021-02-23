#include <stdio.h>
#include <stdlib.h>
#define max_pupils 780
#define max_amount_classes 26
#define min_pupils_class 20
#define max_pupils_class 30

//*************************Angabe*************************
typedef struct class
{
  int pupilcounter;
  char letter;
  int number;
  struct class *next;
} class;

typedef struct school
{
  class *classlist;
  int total_pupils;
  int total_classes;
  int operation;
} school;

//Constructers
void error();
void free_all();
void printSchool();
void printYear();
void printClass();
int calculate_classes();
class *create_class();
void update_existing_classes();
void new_class();
void free_all();

void printSchool(school *_school)
{

  if (_school->classlist != NULL)
  {
    for (class *x = _school->classlist; x != NULL; x = x->next)
    {
      printf("\n%d%c - %d", x->number, x->letter, x->pupilcounter);
    }
    printf("\nTotal: %d pupils - %d class(es)", _school->total_pupils, _school->total_classes);
    printf("\nSchool is operating since %d year(s)", _school->operation);
  }
  else
  {
    error(-3);
  }
}
void printYear(school *_school)
{
  int year = 0;
  int pupil_count = 0;
  int class_count = 0;

  if (_school->classlist != NULL)
  {
    printf("\nEnter a year (1-4): ");
    scanf("%d", &year);
    for (class *x = _school->classlist; x != NULL; x = x->next)
    {
      if (year == x->number)
      {
        printf("\n%d%c - %d", x->number, x->letter, x->pupilcounter);
        pupil_count += x->pupilcounter;
        class_count++;
      }
    }
    if (class_count > 0)
      printf("\nTotal: %d pupils - %d class(es)", pupil_count, class_count);
    else
      error(-4);
  }
  else
  {
    error(-3);
  }
}
void printClass(school *_school)
{
  int number;
  char letter;

  if (_school->classlist != NULL)
  {
    printf("\nEnter a class (e.g.: 2B): ");
    scanf("%d %c", &number, &letter);
    for (class *x = _school->classlist; x != NULL; x = x->next)
    {
      if (x->letter == letter && x->number == number)
      {
        printf("\nClass %d%c has %d pupils", x->number, x->letter, x->pupilcounter);
        return;
      }
    }
    error(-4);
  }
  else
  {
    error(-3);
  }
}
//********************************************************
void error(int msg_code)
{
  switch (msg_code)
  {
  case -1:
    printf("\nInvalid selection");
    break;
  case -2:
    printf("\nNot enough students");
    break;
  case -3:
    printf("\nSchool: no classes");
    break;
  case -4:
    printf("\nNo such class");
  }
}
int calculate_classes(int pupil_amount)
{
  int class_amount = 0;
  int remainder = 30;
  for (int i = min_pupils_class; i < max_pupils_class; i++)
  {
    if (!(pupil_amount % i) && (pupil_amount / i < max_amount_classes))
    {
      class_amount = pupil_amount / i;
      break;
    }
    else
    {
      if ((pupil_amount % i) < remainder)
      {
        if ((pupil_amount / i) <= max_amount_classes)
        {
          remainder = pupil_amount % i;
          class_amount = pupil_amount / i;
        }
      }
    }
  }
  return class_amount;
}
class *create_class(int pupil_amount, int opcode, school *_school)
{
  int amount_classes = 0;
  int distributed_pupils = 0;
  //15-30 Pupils
  class *new_class = malloc(sizeof(class));
  new_class->letter = 'A';
  new_class->number = 1;
  new_class->pupilcounter = pupil_amount;
  new_class->next = NULL;
  if (opcode == 1)
  {
    new_class->next = _school->classlist;
    _school->total_classes++;
    _school->total_pupils += pupil_amount;
    return new_class;
  }

  //30-40 Pupils
  if (opcode == 2)
  {
    class *new_class2 = malloc(sizeof(class));
    new_class2->letter = 'B';
    new_class2->number = 1;
    new_class2->pupilcounter = pupil_amount / 2;
    new_class2->next = _school->classlist;

    new_class->pupilcounter = pupil_amount - new_class2->pupilcounter;
    new_class->next = new_class2;

    _school->total_pupils += pupil_amount;
    _school->total_classes += 2;

    return new_class;
  }
  //>40 Pupils
  else
  {
    amount_classes = calculate_classes(pupil_amount);
    amount_classes--;
    if (amount_classes == 0)
      exit(-1);

    for (int i = 0; i < amount_classes; i++)
    {
      class *x = new_class;
      for (; x->next != NULL; x = x->next)
      {
        continue;
      }
      class *new_class2 = malloc(sizeof(class));
      new_class2->letter = x->letter + 1;
      new_class2->number = 1;
      new_class2->pupilcounter = pupil_amount / (amount_classes + 1);
      distributed_pupils += new_class2->pupilcounter;
      if (i + 1 == amount_classes)
      {
        new_class2->next = _school->classlist;
      }
      else
      {
        new_class2->next = NULL;
      }
      x->next = new_class2;
    }
    new_class->pupilcounter = pupil_amount / (amount_classes + 1);
    distributed_pupils += new_class->pupilcounter;
    class *iterator = new_class;
    for (int i = 0; i < (pupil_amount - distributed_pupils); i++)
    {
      iterator->pupilcounter++;
      iterator = iterator->next;
    }
    _school->total_pupils += pupil_amount;
    _school->total_classes += amount_classes + 1;
    return new_class;
  }
}
void update_existing_classes(school *_school)
{
  _school->operation++;
  if (_school->classlist != NULL)
  {
    if (_school->classlist->number == 4)
    {
      free_all(_school->classlist, _school);
      _school->classlist = NULL;
    }
    else
    {
      for (class *x = _school->classlist; x != NULL; x = x->next)
      {

        if (x->number < 4)
        {
          x->number++;
        }
        if (x->next == NULL || x->next->number == 4)
        {
          free_all(x->next, _school);
          x->next = NULL;
          break;
        }
      }
    }
  }
}

void new_class(school *_school)
{

  int pupil_amount = 0;
  update_existing_classes(_school);
  printf("\nEnter the number of students: ");
  scanf("%d", &pupil_amount);
  if (pupil_amount < 15 || pupil_amount > max_pupils)
  {
    error(-2);
  }
  else if (pupil_amount < 31)
  {
    _school->classlist = create_class(pupil_amount, 1, _school);
  }
  else if (pupil_amount < 40)
  {
    _school->classlist = create_class(pupil_amount, 2, _school);
  }
  else
  {
    _school->classlist = create_class(pupil_amount, 0, _school);
  }
}
void free_all(class *_classlist, school *_school)
{
  class *ptr = _classlist;

  if (ptr != NULL)
  {
    class *t_ptr = ptr->next;
    for (; ptr->next != NULL;)
    {
      _school->total_pupils -= ptr->pupilcounter;
      _school->total_classes--;
      free(ptr);
      ptr = t_ptr;
      t_ptr = ptr->next;
    }
    _school->total_pupils -= ptr->pupilcounter;
    _school->total_classes--;
    free(ptr);
  }
}
int main()
{
  school my_school = {0};
  char option = ' ';
  while (option != 'x')
  {
    printf("\nChoose action: school (s), year (y), class (c), new (n), exit (x): ");
    scanf(" %c", &option);
    switch (option)
    {
    case 's':
      printSchool(&my_school);
      break;
    case 'y':
      printYear(&my_school);
      break;
    case 'c':
      printClass(&my_school);
      break;
    case 'n':
      new_class(&my_school);
      break;
    case 'x':
      continue;
      break;
    default:
      error(-1);
      break;
    }
  }
  free_all(my_school.classlist, &my_school);
  return 0;
}