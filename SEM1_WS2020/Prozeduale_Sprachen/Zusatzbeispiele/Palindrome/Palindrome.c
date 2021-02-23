#include <stdio.h>
#include <stdlib.h>

int is_palindrome(char*message)
{
  char ohne_satzzeichen[40];
  int j=0;
  for(int i = 0; i<40;i++)
  {
    if(message[i]>64 && message[i]<91)
    {
      ohne_satzzeichen[j]=message[i];
      j++;
    }
    if((message[i]>96 && message[i]<123))
    {
      ohne_satzzeichen[j]=message[i]-32;
      j++;
    }
    if(message[i]=='\n' || message[i]=='\0')
      break;
  }
  for(int i =0;i<j;i++)
  {
    if(ohne_satzzeichen[i]!=ohne_satzzeichen[j-i-1])
      return 0;
    if(i==(j-i-1))
      break;
  }
  return 1;
}

int main()
{
  char message[41]="";
  printf(": ");
  scanf("%40[^\n]",message);
  if(is_palindrome(message))
    printf("true");
  else
    printf("false");

}