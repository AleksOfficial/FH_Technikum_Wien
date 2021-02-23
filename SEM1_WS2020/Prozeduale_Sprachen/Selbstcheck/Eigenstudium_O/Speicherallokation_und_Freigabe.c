#include <stdio.h>
#include <stdlib.h>

int main()
{
  int * p1 = (int*) malloc(sizeof(int));
  double *p2 = (double*) malloc(sizeof(double));
    printf("%lu",sizeof(int));
    printf("\n");
    printf("%lu",sizeof(double));
    printf("\n");
    printf("%lu",sizeof(p1));
    printf("\n");
    printf("%lu",sizeof(p2));
    free(p1);
    free(p2);
}