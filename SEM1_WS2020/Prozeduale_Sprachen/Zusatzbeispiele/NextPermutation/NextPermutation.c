#include <stdio.h>
#include <stdlib.h>
//wow. I focused on their description and i got rekt so hard. it's ridiculous. rip day. honestly. what a way to waste time on this bs. 
//I guess I was too primed on their description and tried to look for the answer in it.
//in reality, I should have come up with my own solution. I guess I wouldn't have without google tbf.  
int * swap_positions(int * array, int pos1, int pos2)
{
  
  array[pos1]=array[pos1]+array[pos2];
  array[pos2]=array[pos1]-array[pos2];
  array[pos1]=array[pos1]-array[pos2];
  return array;
}

int find_biggest_index1(int * next_permutation, int length)
{ 
  int result =length;
  for(int i=0;i<length-1;i++)
  {
    if(next_permutation[i]<next_permutation[i+1])
    {
      result=i;
    }
  }
  return result;
}

int find_biggest_index2(int * next_permutation, int length, int index1)
{
  int result =length;
  for(int i=length-1;i!=0;i--)
  {
    if(next_permutation[index1]<next_permutation[i])
    {
      result=i;
      break;
    } 
  }
  return result;
}

int * inverse_subarray(int * subarray, int index,int length)
{
  int subtractor =0;
  int limit = length - index;
  limit /=2;
  for(int i = index; subtractor<limit;i++)
  {
    if(i!=length-1-subtractor)
      swap_positions(subarray,i,length-1-subtractor);
    subtractor++;
    /*
    for(int j=0;j<length;j++)
    {
      printf("%d ",subarray[j]);
    }
    printf("\n");
    */
  }
  return subarray;
}

int * next_permutation(int * next_permutation, int length)
{
  int index1=length;
  int index2=length;
  
  //find biggest index x => P[x] < P[x+1]
  index1 = find_biggest_index1(next_permutation,length);
  
  if(index1==length)
  {
    next_permutation=inverse_subarray(next_permutation,0,length);
    return next_permutation;
  }
    
  
  //find largest y: P[x]<P[y]
  index2 = find_biggest_index2(next_permutation,length,index1);

  //swap P[x] and P[y]
  next_permutation = swap_positions(next_permutation,index1,index2);

  //inverse array at P[x+1 .. n]
  next_permutation = inverse_subarray(next_permutation,index1+1,length);
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
}