#include <stdio.h>

int main(){
  enum days {sunday,monday,tuesday,wednesday,thursday,friday,saturday}; // in c it's quite useless... sorry. 
  char days[7][10]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
  int wochentag;
  scanf("%d",&wochentag);
  if(wochentag>=0 && wochentag<=6)
  {
      printf("%s",days[wochentag]);
  }
  else printf("invalid");
  

}