#include <stdio.h>

int main()
{
    long long int EANnumber=0;
    int EAN_split[13];
    printf(": ");
    scanf("%lld",&EANnumber);
    for(int i =0;i<13;i++)
    {
        EAN_split[12-i]=EANnumber%10;
        EANnumber = EANnumber/10;
    }
    //calc sums
    int sum1=0;
    int sum2=0;
    for(int i = 0; i<12; i++)
    {
        if(i%2)
        {
            sum1=sum1+EAN_split[i];
        }
        if(i%2!=1)
        {
            sum2=sum2+EAN_split[i];
        }
    }
    //sum1*3+sum2, total-1, rest von total/10,9-rest
    int total = sum1*3+sum2;
    total--;
    total = total%10;
    int check = 9-total;
    if(check ==EAN_split[12])
    {
        printf("VALID");
    }
    else
    {
        printf("INVALID");
    }
    
    
    
    


}