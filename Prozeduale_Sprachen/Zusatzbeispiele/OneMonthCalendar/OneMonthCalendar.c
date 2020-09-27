#include <stdio.h>

int main(){
    int m_days = 0, w_day =0,temp_days=0, tm_days=1;

    printf("number of days in month: ");
    scanf("%d",&m_days);
    printf("starting day of week (1=Monday, 7=Sunday): ");
    scanf("%d",&w_day);
    printf("\n");

    while(m_days>0)
    {
        for(int i =0;i<7;i++)
        {
            if(w_day>1)
            {
                printf("  ");
                temp_days++;
                w_day--;
            } else if(m_days>0)
            {
                printf("%2d",tm_days);
                tm_days++;
                m_days--;
            }
            else if(temp_days>1) {
                printf("  ");
                temp_days--;
            }
            printf(" ");
        }
    printf("\n");
    }
}