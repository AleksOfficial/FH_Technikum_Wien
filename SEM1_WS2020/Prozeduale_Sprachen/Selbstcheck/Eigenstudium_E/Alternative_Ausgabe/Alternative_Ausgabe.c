#include <stdio.h>

int main(){
    int p1,ue1;
    scanf("%d %d",&p1,&ue1);
    if(p1>50){
        if(p1+ue1 >69)
        {
            printf("Positiv");
            return 0;
        }
    }
    printf("Negativ");
    return -1;

}