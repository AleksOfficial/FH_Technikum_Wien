#include <stdio.h>

int main()
{
  int x;
  scanf("%d",&x);
  int arr_int[x];
  double arr_double[x];
  char arr_char[x];
  printf("%ld\n",sizeof(arr_int));
  printf("%ld\n",sizeof(arr_double));
  printf("%ld\n",sizeof(arr_char));
}