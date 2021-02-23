#include <stdio.h>

int main(){
/*
{
  int bruh[256];
  int summe=0;
  int i;
  for(i=0;(bruh[i]!=0)||(i<5);i++)
  {
    scanf("%d",&bruh[i]);
    summe+=bruh[i];
  }
  float av;
  av = summe/(i-1);
  printf("%.2f",av);
  }*/
  char lol[256];
  for(int i=0;; ++i)
  {
    scanf("%c",&lol[i]);
    if(lol[i]=='!') break;
    
    char str[2]="";
    scanf("%s", &str);
    lol[i] = str[0];
    if (str[0]=='!') break;
    
    
  }
  int l=0;
  for(int i=0; lol[i]!= '!'; i++)
  {
    l++;
  }
  printf("%d\n", l);

  for (int i=0; lol[i]!= '!';i++)
  {
    printf("%c",lol[i]);
  }
} 