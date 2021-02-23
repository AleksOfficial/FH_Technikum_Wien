#include <stdio.h>

int main()
{
    int hour=0,minutes=0;
    
    printf("24h time: ");
    scanf("%d:%d",&hour,&minutes);
    //ich glaub, mit einem switch case is es schöner
    if (hour == 12)
    {
        printf("12h time: %2d:%02d PM",hour,minutes);
        return 0;
    }
    else if (hour == 0)
    {
        hour = 12;
        printf("12h time: %2d:%02d AM",hour,minutes);
        return 0;
    }
    else if (hour>12)
    {
        hour = hour-12;
        printf("12h time: %2d:%02d PM",hour,minutes);
        return 0;
        
    }
    else
    {
        printf("12h time: %2d:%02d AM",hour,minutes);
        return 0;
    }
    
}