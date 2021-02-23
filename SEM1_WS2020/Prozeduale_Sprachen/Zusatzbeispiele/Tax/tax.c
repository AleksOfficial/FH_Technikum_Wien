#include <stdio.h>

int main(){
    double input = 0,result = 0;
    double tax = 1.2;
    printf(": ");
    scanf("%lf",&input);
    result = input*tax;
    printf("With tax: %.2f",result);
    return 0;
}