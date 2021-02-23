#include <stdio.h>

int recursive_power(int number, int amount){
  if(amount==0)
  {
    number = 1;
    printf("%d\n",number);
    return number;
  }
  else if(amount == 1)
  {
    printf("%d\n", number);
    return number;
  }
  else{
    number = number * recursive_power(number,amount-1);
    printf("%d\n", number);
    return number;
  }

  return 0;
}

int main(){
  int z1, z2;
  scanf("%d %d",&z1,&z2);
  z1=recursive_power(z1,z2);
}