#include <stdio.h>

int main(){
  typedef volatile unsigned long long int vullint;
  vullint a,b;
  scanf("%llu %llu",&a,&b);
  printf("%llu",a+b);
}