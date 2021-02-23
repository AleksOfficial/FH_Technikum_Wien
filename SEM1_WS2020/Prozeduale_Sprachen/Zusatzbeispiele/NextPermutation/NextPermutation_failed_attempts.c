//wow. I focused on their description and i got rekt so hard. it's ridiculous. rip day. honestly. what a way to waste time on this bs. 
//I guess I was too primed on their description and tried to look for the answer in it. Only to discover that it was a description of what the algorithm did in this particular case. 
//however, this is not what the algorithm does generally. And that's what I tried to implement. 
//in reality, I should have come up with my own solution and not read their bs. I guess I wouldn't have without google tbf. This is an interview question after all. Anotherone bites the dust!
/*

#include <stdio.h>
#include <stdlib.h>

int *swap_positions(int *array, int pos1, int pos2)
{

  array[pos1] = array[pos1] + array[pos2];
  array[pos2] = array[pos1] - array[pos2];
  array[pos1] = array[pos1] - array[pos2];
  return array;
}

int *subsort_array(int *array, int pos, int maxlen)
{
  int unsorted = 1;
  int subpos = 1;
  while (unsorted)
  {
    unsorted = 0;
    subpos = 1;
    for (int i = pos + 1; subpos < maxlen; i++)
    {
      if (array[i] > array[i + 1])
      {
        unsorted = 1;
        swap_positions(array, i, i + 1);
      }
      subpos++;
    }
  }
  return array;
}

int *next_permutation(int *next_permutation, int length)
{
  int position_swap1 = 0, position_swap2 = length - 1, tmp_pos = 0;
  int sub_length_max = 1;
  int sub_length = 1;

  //find max sublength
  for (int i = 0; i < length - 1; i++)
  {
    if (next_permutation[i] > next_permutation[i + 1] && i != length - 2)
      sub_length++;
    else
    {

      if (sub_length >= sub_length_max)
      {
        sub_length_max = sub_length;
        position_swap1 = tmp_pos;
        
        if (i == length - 2)
        {
          if (next_permutation[i] > next_permutation[i + 1])
          {
            sub_length++;
          }
          else
          {
            if(sub_length>=sub_length_max)
            {
              sub_length_max=sub_length;
              position_swap1=tmp_pos+1;

            }
          }
          
        }
      }
      sub_length = 1;
      tmp_pos = i;
    }
  }
  //find next highest number in sublength & swap
  for (int i = position_swap1 + sub_length_max; i != position_swap1 + 1; i--)
  {
    if (next_permutation[i] > next_permutation[position_swap1])
    {
      position_swap2 = i;
      break;
    }
  }
  next_permutation = swap_positions(next_permutation, position_swap1, position_swap2);

  //sort sublength
  next_permutation = subsort_array(next_permutation, position_swap1, sub_length_max);
  return next_permutation;
}

int main()
{
  int length;
  printf(": ");
  scanf("%d", &length);
  printf(": ");
  int *permutations = calloc(length, sizeof(int));
  for (int i = 0; i < length; i++)
  {
    scanf("%d", &permutations[i]);
  }

  permutations = next_permutation(permutations, length);
  printf("\n");
  for (int i = 0; i < length; i++)
  {
    printf("%d ", permutations[i]);
  }
  free(permutations);
}
#include <stdio.h>
#include <stdlib.h>



int * swap_positions(int * array, int pos1, int pos2)
{
  
  array[pos1]=array[pos1]+array[pos2];
  array[pos2]=array[pos1]-array[pos2];
  array[pos1]=array[pos1]-array[pos2];
  return array;
}

int * subsort_array(int * array,int pos,int maxlen)
{
  int unsorted = 1;
  int subpos =1;
  while(unsorted)
  {
    unsorted=0;
    subpos=1;
    for(int i=pos+1;subpos<maxlen;i++)
    {
      if(array[i]>array[i+1])
      {
        unsorted=1;
        swap_positions(array,i,i+1);
      }
      subpos++;
    }
  }
  return array;
}

int * sub_length_and_pos(int * next_permutation, int length)
{ 
  int result =0;
  int sub_length = 1;
  int tmp_pos=0;
  for(int i=0;i<length-1;i++)
  {
    if(next_permutation[i]>next_permutation[i+1] && i!=length-2)
      sub_length++;
    else
    {
      if(next_permutation[i]>next_permutation[i+1])
        {
          sub_length++;
         
        }
      if(sub_length>=result[0])
      {          
        result[0] = sub_length;
        result[1] = tmp_pos;
      }
      sub_length=1;
      tmp_pos=i;
    }
  }
  return result;
}

int * next_permutation(int * next_permutation, int length)
{
  int * pos_and_length = malloc(sizeof(int)*2);
  int position_swap2=length-1, tmp_pos = 0;
  int sub_length_max=1;
  int sub_length=1;
  
  //
  pos_and_length = sub_length_and_pos(next_permutation,length);
  
  //find next highest number in sublength & swap
  for(int i=position_swap1+sub_length_max;i!=position_swap1+1;i--)
  {
    if(next_permutation[i]>next_permutation[position_swap1])
    {
      position_swap2=i;
      break;
    }

  }
  next_permutation = swap_positions(next_permutation,position_swap1,position_swap2);

  //sort sublength
  next_permutation = subsort_array(next_permutation,position_swap1,sub_length_max);
  return next_permutation;

  
  
}

int main()
{
  int length;
  printf(": ");
  scanf("%d",&length);
  printf(": ");
  int * permutations=calloc(length,sizeof(int));
  for(int i = 0;i<length;i++)
  {
    scanf("%d",&permutations[i]);
  }

  permutations = next_permutation(permutations,length);
  printf("\n");
  for(int i = 0;i<length;i++)
  {
    printf("%d ",permutations[i]);
  }
  free(permutations);
}*/