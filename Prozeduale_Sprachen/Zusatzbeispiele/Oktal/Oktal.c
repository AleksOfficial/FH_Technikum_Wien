#include <stdio.h>

int self_pow(int number, int length){
    // pow(8,2) -> 8^2 = 8*8 -> 64
    // pow(8,3) -> 8^3 = 8*8*8 -> 512
    // pow(8,0) -> 8^0 = 1
    int sum = 1;
    for (int i =0;i<length;i++)
    {
        sum*=number;
    }
    return sum;
}

int main(){
    //aber was wenn eine Zahl mehr als 3 Stellen hat?
    int oktal = 0,decimal = 0,ZS =0,length = 0;
    printf(": ");
    scanf("%d",&oktal);
    //Funktioniert normalerweise auch bei längeren zahlen
    while(oktal > 0)
    {
        
        decimal = decimal + (oktal % 10) *self_pow(8,length);
        oktal = oktal /10;
        length++;
    }
    printf("dec.: %d\n",decimal);
    while(decimal>0)
    {
        ZS += decimal%10;
        decimal /= 10;
    }
    printf("ZS: %d",ZS);


    return 0;
}