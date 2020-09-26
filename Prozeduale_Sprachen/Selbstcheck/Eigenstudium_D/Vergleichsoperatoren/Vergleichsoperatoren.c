#include <stdio.h>

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d\n",x>0&&x<y);
    printf("%d\n",x==y||y<0);
    printf("%d\n",(x==0||y==0)&&y!=0);
    
}