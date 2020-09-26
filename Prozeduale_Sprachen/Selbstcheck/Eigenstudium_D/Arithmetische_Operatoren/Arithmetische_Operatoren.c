#include <stdio.h>

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d\n",y+5);
    x=y+5;
    printf("%d\n",y*3);
    y*=3;
    printf("%d\n",y/2);
    y/=2;
    printf("%d\n",y%x);
    
}