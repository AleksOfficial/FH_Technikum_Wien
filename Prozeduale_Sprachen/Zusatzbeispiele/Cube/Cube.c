#include <stdio.h>
//#include <math.h>

int self_pow(int value, int amount_of_times)
{
    int result =1;
    for(int i = 0; i<amount_of_times; i++)
    {
        result = result *value;
    }
    return result;
}

int calculate_surface(int side)
{
    return self_pow(side,2)*6;
    //return round(pow(side,2)*6);
}
int calculate_volume(int side)
{
    return self_pow(side,3);
    //return round(pow(side,3));  
}

int main(){
    int side = 0,result = 0;
    printf(": ");
    scanf("%d",&side);
    result = calculate_surface(side);
    printf("Surface area: %d\n", result);
    result = calculate_volume(side);
    printf("Volume: %d",result);
    return 0;
}
