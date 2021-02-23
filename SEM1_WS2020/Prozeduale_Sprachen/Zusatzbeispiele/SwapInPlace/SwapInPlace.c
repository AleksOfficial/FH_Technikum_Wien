#include <stdio.h>

int exchange(int val1, int val2)
{   
    //funktioniert nicht in c 
    //return val2,val1 
    return 0;
}

int main(){
    //einfache Lösung geht leider nicht lel.
    //mit pointers? nah.. (Eigentlich keine variable )
    //ansonsten mit bitoperatoren oder so.  
    int a = 0,b = 0;
    printf(": ");
    scanf("%d %d",&a,&b);

    printf("Before:\n");
    printf(" a = %d\n",a);
    printf(" b: %d\n",b);
    //exchange(a,b);
    a = a^b;
    b = a^b;
    a = a^b;
    printf("After:\n");
    printf(" a = %d\n",a);
    printf(" b: %d",b);  
    return 0;
}