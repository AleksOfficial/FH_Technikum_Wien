#include <stdio.h>

int power(int x, int y)
{
  int sum=1;
  for(int i = 0; i<y; i++)
  {
    sum = sum*x;
  }
  return sum;
}

int faculty(int x)
{
  int sum=1;
  for(int i=1; i<=x; i++)
  {
    sum = sum*i;
  }
  return sum;
}

int main()
{
  int x, y;
  char operator;
  scanf("%d",&x);
  scanf("%d",&y);
  scanf(" %c",&operator);

  if(operator =='a')
  {
    printf("%d",power(x,y));
  }
  if(operator =='b')
  {
    printf("%d",(faculty(x)+faculty(y)));
  }
  if(operator =='c')
  {
    printf("%d",faculty(power(x,y)));
  }

}