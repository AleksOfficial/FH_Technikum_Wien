#include <stdio.h>
#include <stdlib.h>


void swap_position(int *pos1, int *pos2)
{
  *(pos1) = *(pos1) + *(pos2);
  *(pos2) = *(pos1) - *(pos2);
  *(pos1) = *(pos1) - *(pos2);
}

void bubble_sort(int length, int array[length])
{
  int unsorted = 1;
  while (unsorted)
  {
    unsorted = 0;
    for (int i = 0; i < length - 1; i++)
    {

      if (array[i] > array[i + 1])
      {
        swap_position(&array[i], &array[i + 1]);
        unsorted = 1;
      }
    }
  }
}


//copy paste qsort function from book
void my_qsort(int *links, int *rechts) {
   int *ptr1 = links;
   int *ptr2 = rechts;
   int w, midvalue;
   //midvalue = *(links + (rechts - links >> 1));
   midvalue=*links+*rechts / 2;
   do {
      while(*ptr1 < midvalue) ptr1++;
      while(*ptr2 > midvalue) ptr2--;
      if(ptr1 > ptr2)
         break;
      w = *ptr1;
      *ptr1 = *ptr2;
      *ptr2 = w;
   } while(++ptr1 <= --ptr2);
   if(links < ptr2) my_qsort(links, ptr2);
   if(ptr1 < rechts) my_qsort(ptr1, rechts);
}
/*
int *quicksort(int length, int index, int array[length])
{
  int mid = length / 2;

  if (array[index] < array[mid])
  {
    quicksort(mid, )
  }
}*/
//qsort funktion
int cmp_integer(const void *wert1, const void *wert2) {
   return (*(int*)wert1 - *(int*)wert2);
}
int main()
{
  int len1, len2;
  printf(": ");
  scanf("%d %d", &len1, &len2);
  int array1[len1];
  int array2[len2];

  //printf(": ");
  for (int i = 0; i < len1; i++)
  {
    scanf("%d", &array1[i]);
  }

  //printf(": ");
  for (int i = 0; i < len2; i++)
  {
    scanf("%d", &array2[i]);
  }
  //all methods of getting the result
  
  //I'll implement other algorithms later
  //bubble_sort(len1, array1);
  //bubble_sort(len2, array2);

  //my_qsort(array1,array1+len1-1);
  //my_qsort(array2,array2+len2-1);
  //This is actually a stdlib function in C... damn
  //qsort(array1,len1,sizeof(int),cmp_integer);
  //qsort(array2,len2,sizeof(int),cmp_integer);
  int min_difference = abs(array1[0] - array2[0]), min_pos1 = 0, min_pos2 = 0;
  int temp_difference = -1;
  for (int j = 0; j < len1; j++)
  {
    temp_difference = -1;
    for (int i = 0; i < len2; i++)
    {
      if (temp_difference == -1)
      {
        temp_difference = abs(array1[j] - array2[i]);
      }
      if (temp_difference < abs(array1[j] - array2[i]))
      {
        break;
      }
      else
      {
        temp_difference=abs(array1[j] - array2[i]);
      }
      if (min_difference > abs(array1[j] - array2[i]))
      {
        min_difference = abs(array1[j] - array2[i]);
        min_pos1 = j;
        min_pos2 = i;
      }
    }
  }

  for (int i = 0; i < len1; i++)
  {
    printf("%d ", array1[i]);
  }
  printf("\n");
  for (int i = 0; i < len2; i++)
  {
    printf("%d ", array2[i]);
  }
  
  printf("\n");
  printf("%d (%d, %d)", min_difference, array1[min_pos1], array2[min_pos2]);
}