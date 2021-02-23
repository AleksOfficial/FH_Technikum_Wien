#include <stdio.h>

int main()
{
  int position,leader=1,nr1=1;
for (int i=2;;i++)
{
  printf(": ");
  scanf("%d",&position);
  if(position==0)
  {
    break;
  }
  if(position<=nr1){
    nr1++;
    printf("position #1: %d\n",nr1);
  }
  if (position ==1){
    printf("new leader: #%d\n",i);
    leader = i;
  }
}
printf("final position #1: %d\n",nr1);
printf("winner: #%d",leader);

}