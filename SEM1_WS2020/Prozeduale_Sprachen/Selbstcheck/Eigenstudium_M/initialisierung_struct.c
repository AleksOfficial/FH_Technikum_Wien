#include <stdio.h>
struct Point{
  int x;
  int y;
};

int main(){
  struct Point lel;
  scanf("%d %d",&lel.x,&lel.y);
  printf("%d",lel.x-lel.y);
  
}