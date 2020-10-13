#include <stdio.h>


int fibonacci(int number){
  if (number<=0){
    printf("%d\n",number);
    return 0;
  }
  if(number == 1)
  {
    printf("%d\n",number);
    return 1;
  }
  else
  {
    number=fibonacci(number-1)+fibonacci(number-2);
    printf("%d\n",number);
    return number;
  }
  
}

int main(){
  int input,x;
  scanf("%d",&input);
  x = fibonacci(input);
  printf("%d. Fibonacci-Zahl = %d",input,x); // they can't even spell his name right... loool TESTCASE: Fibonnaci, change if u want. 
}