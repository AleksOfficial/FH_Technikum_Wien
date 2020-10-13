#include <stdio.h>

void swap(int * z1, int* z2)
{
  *z1 = *z1 + *z2;
  *z2 = *z1 - *z2;
  *z1 = *z1 - *z2;
}
int main(){
  int zahl1,zahl2;
  int* p = &zahl1;
  int* q = &zahl2;
  scanf("%d %d",p,q);
  swap(p,q);
  printf("%d\n%d",zahl1,zahl2);
}