#include <stdio.h>
#include <stdlib.h>

void check_if_in_range(int time, int minutes)
{
    if(time>24*60 || time <0 || minutes >59)
    {
        printf("FORMAT ERROR");
        exit(-1);
    }
}

int main()
{
    int hour1 = 0, minutes1 = 0, total1 = 0, hour2 = 0, minutes2 = 0, total2 = 0, result_total = 0, res_minutes = 0, res_hour = 0;
    printf(": ");
    scanf("%d:%d",&hour1,&minutes1);
    printf(": ");
    scanf("%d:%d",&hour2,&minutes2);
    total1 = hour1*60 + minutes1;
    total2 = hour2*60 + minutes2;
    check_if_in_range(total1,minutes1);
    check_if_in_range(total2,minutes2);
    if(total1>total2)
    {
        printf("NOT VALID");
        exit(-2);
    }else
    {
        result_total =total2-total1;
        res_minutes = result_total%60;
        res_hour = (result_total-res_minutes)/60;
        printf("%2d:%02d",res_hour,res_minutes);
        return 0;
    }
        
    
}