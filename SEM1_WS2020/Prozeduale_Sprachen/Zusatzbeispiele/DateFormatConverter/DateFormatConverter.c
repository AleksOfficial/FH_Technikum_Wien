#include <stdio.h>

int main(){
    int day,month,year = 0;
    printf(": ");
    scanf("%d/%d/%d",&month,&day,&year);
    printf("%02d.%02d.%04d",day,month,year);
    return 0;

}