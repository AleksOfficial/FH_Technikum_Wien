#include <stdio.h>
struct Point{
  int x;
  int y;
};

void swap(struct Point *x){
  x->x += x->y;
  x->y = x->x-x->y;
  x->x = x->x-x->y;
  
}

int main(){
  struct Point lel;
  scanf("%d %d",&lel.x,&lel.y);
  printf("%d\n",lel.x-lel.y);
  swap(&lel);
  printf("%d",lel.x-lel.y);
}