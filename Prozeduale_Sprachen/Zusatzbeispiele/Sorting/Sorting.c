#include <stdio.h>
void print(int array[],int sel1, int sel2,int step,int length)
{
  printf("Step %d: ",step);
  if(sel1 == sel2)
  {
    
    for(int i = 0;i<sel1;i++)
    {
      printf("%d ",array[i]);
    }
    printf("[(%d)] ",array[sel1]);
    for(int i = sel1+1;i<length;i++)
    {
      printf("%d ",array[i]);
    }
    printf("\n");
  }
  else
  {
    for(int i = 0;i<length;i++)
    {
      if(i == sel1)
        printf("(%d) ",array[i]);
      else if(i == sel2)
        printf("[%d] ",array[i]);
      else
        printf("%d ",array[i]);
    }
    printf("\n");
  }
}
void selection_sort(int a[], int N,int *comparison, int *swaps)
{
    int i, j, min, t;
    for(i = 0; i < N-1; i++)
    {
        min = i;
        for (j = i+1; j < N; j++) // suche kleinstes El.
        {
            if (a[j] < a[min])
                min = j; // merke Position des kleinsten El.
            (*comparison)++;
        }
        print(a,i,min,i+1,N);
        t = a[min]; // Tausch
        a[min] = a[i];
        a[i] = t;
        (*swaps)++;
    }
} 

int main()
{
  int array[1024] = {0};
  int input = -1;
  int length = 0;
  int comparison=0;
  int swaps = 0;
  printf(": ");
  while(42)
  {
    
    scanf("%d",&input);
    if(input == 0)
      break;
    array[length] = input;
    length++;
  }
  printf("\n");
  selection_sort(array,length,&comparison,&swaps);
  printf("Result: ");
  int x = 0;
  while(array[x]!=0)
  {

    printf("%d ",array[x]);
    x++;
  } 
  printf("\n\nNumber of comparisons: %d",comparison);
  printf("\nNumber of swaps: %d",swaps);

}