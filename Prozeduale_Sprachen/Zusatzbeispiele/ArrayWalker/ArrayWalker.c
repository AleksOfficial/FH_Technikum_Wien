#include <stdio.h>
#include <stdlib.h>
#define MAX_X 10
#define MAX_Y 10

void update_field(int **field, int *position, int *counter)
{
  field[position[0]][position[1]] = *(counter);
  *(counter) = *(counter) + 1;
  if (*(counter) == 27)
    *(counter) = 1;
}

int valid_position(int **field, int *position, char *command)
{
  if (*(command) == 'n')
  {
    if (position[0] != 0)
    {
      if (field[position[0] - 1][position[1]] == 0)
      {
        return 1;
      }
    }
  }

  if (*(command) == 's')
  {
    if (position[0] + 1 < MAX_Y)
    {
      if (field[position[0] + 1][position[1]] == 0)
      {
        return 1;
      }
    }
  }

  if (*(command) == 'e')
  {
    if (position[1] + 1 < MAX_X)
    {
      if (field[position[0]][position[1] + 1] == 0)
      {
        return 1;
      }
    }
  }

  if (*(command) == 'w')
  {
    if (position[1] != 0)
    {
      if (field[position[0]][position[1] - 1] == 0)
      {
        return 1;
      }
    }
  }
  if (*(command) == 'x')
  {
    return 1;
  }
  return 0;
}

void walk_field(int **field, int *position, char *command, int *counter)
{

  while (42)
  {
    printf("walk to:\n");
    scanf(" %c", command);
    if (valid_position(field, position, command))
    {
      switch (*(command))
      {
      case 'n':
        position[0]--;
        break;

      case 's':

        position[0]++;
        break;

      case 'e':

        position[1]++;
        break;

      case 'w':
        position[1]--;
        break;
      }
      //updatefield here
      update_field(field, position, counter);
      break;
    }
    else
    {
      printf("not possible\n");
    }
  }
}

void print_field(int **field)
{
  for (int i = 0; i < MAX_Y; i++)
  {
    
    for (int j = 0; j < MAX_X; j++)
    {
      if (field[i][j] == 0)
        printf(".");
      else
      {
        printf("%c", 64 + field[i][j]);
      }
    }
    printf("\n");
  }
}
int **createArray(int m, int n)
{
  int *values = calloc(m * n, sizeof(int));
  int **rows = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    rows[i] = values + i * m;
  }
  return rows;
}

void free_all(int **arr)
{
  free(*arr);
  free(arr);
}
int main()
{
  //maybe there is a better way to do this.. but im not quite sure. ask the lecturer?
  //damn i think i found it on stack overflow. The field needs a constructor function
  int **field = createArray(MAX_X, MAX_Y);

  /*int *field=calloc(10,sizeof(int)*10);
  for(int i=0;i<10;i++)
  {
    field[i]=calloc(10,sizeof(int));
  }
  */

  //typedef int row[10];
  //int * field = calloc(MAX_Y,sizeof(int)*10);
  //int field[MAX_Y][MAX_X] = {0};
  //int (*p)[MAX_X];
  //p=field;
  int *position = calloc(2, sizeof(int));
  int counter = 1;
  update_field(field, position, &counter);
  char command = '\0';
  while (command != 'x')
  {
    print_field(field);
    walk_field(field, position, &command, &counter);
  }
  free_all(field);
}