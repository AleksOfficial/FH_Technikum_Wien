#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 80

//this one will be the easier version with an array.

void print_stats(int *array)
{
  if(array==NULL)
  {
    printf("NOT VALID");
    return;
  }
  for(int i =0;i<MAX_LEN;i++)
  {
    if(array[i]!=0)
      if(i!=0)
      printf("Length %d: %d\n",i,array[i]);
  }
  
}

int *counting(char *message, char delimiter, char terminator)
{
  int length = 0;
  int stop = 1;
  int last_word=0;
  int *lengths=calloc(MAX_LEN,sizeof(int));
  for (int j = 0; stop; j++)
  {
    length=0;
    for (int i = last_word; i < 81; i++)
    {
      if (message[i] < (65 + 27) && message[i] > 64)
        length++;
      else if (message[i] < (97 + 27) && message[i] > 96)
        length++;
      else if (message[i] == delimiter)
      {
        last_word=i+1;
        break;
      }
      else if (message[i] == terminator)
      {
        stop = 0;
        break;
      }
      else
      {
        return NULL;
      }
      
    }
    lengths[length]++;
  }
  return lengths;
}

int main()
{
  char message[MAX_LEN+1] = "";
  int *stats;
  printf(": ");
  scanf("%80[^\n]", message);
  stats=counting(message,' ','.');
  print_stats(stats);
  free(stats);
}