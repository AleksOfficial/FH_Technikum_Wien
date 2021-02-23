#include <stdio.h>

int main()
{
  int size, startValue;
  scanf("%d %d",&size,&startValue);
  int array[size];
  for(int i = 0; i<size; i++)
  {
    array[i]=i+startValue;
    printf("%d\n",array[i]);
  }

}