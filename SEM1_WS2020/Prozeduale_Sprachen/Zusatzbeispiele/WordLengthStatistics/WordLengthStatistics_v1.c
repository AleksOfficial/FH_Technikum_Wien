#include <stdio.h>
#include <stdlib.h>

//shit i think my design is completely wrong here lol. this seems like way too complicated
//nah fuck this this is way too complicated. might complete it later. v1 will be my original thought with sorting.
//I'll change this a more efficient solution
/*
void quick_sort(int*array)
{
  int length_array=1;
  for(int i=0;array[i]!=0;i++)
  {
    length_array++;
  }
  

}
*/
void print_stats(int *length_pointer)
{
  if(length_pointer==NULL)
  {
    printf("NOT VALID");
    return;
  }
  int amount=0, search=0;
  
  for(int i =0;length_pointer[i]!=0;i++)
  {
    amount =0;
    search=length_pointer[i];
    printf("Length: %d: ",search);
    for(int j=0;length_pointer[j]!=0;j++)
    {
      if(length_pointer[j]==search)
        amount++;
    }
    printf("%d\n",amount);
  }
  
}

int *counting(char message[81], char delimiter, char terminator)
{
  int length = 0;
  int stop = 1;
  int last_word=0;
  int *lengths = malloc(sizeof(int));
  for (int j = 1; stop; j++)
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
      lengths[j-1]=length;
      realloc(lengths,sizeof(int)*j);
      lengths[j]=0;
    
      return lengths;
  }
}

int main()
{
  char message[81] = "";
  int * stats;
  printf(": ");
  scanf("%80[^\n]", message);
  stats=counting(message,' ','.');
  quick_sort(stats);
  print_stats(stats);
  free(stats);
}