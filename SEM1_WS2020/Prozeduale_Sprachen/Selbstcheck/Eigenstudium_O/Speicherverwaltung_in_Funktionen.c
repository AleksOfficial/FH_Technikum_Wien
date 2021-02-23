#include <stdio.h>
#include <stdlib.h>

void NULLCHECK(char *ptr)
{
  if (ptr==NULL)
  {
    printf("\nMEMORY ERROR!\n");
    exit(1);
  }
  
}

int string_len(char word[])
{
  int len=0;
  for(int i=0;;i++)
  {
    if(word[i] == '\0')
    {
      len = i;
      break;
    }
  }
  return len;
}

char * mirrored(char word[], char* mirror)
{
  int length = string_len(word);
  mirror = realloc(mirror,(1+length)*sizeof(char));
  NULLCHECK(mirror);
    for(int i = 0;i<(length/2);i++)
    {
      mirror[i]=word[i];
      mirror[length-1-i]=word[i];
    }
    if(length%2)
      mirror[length/2]=word[length/2];
  
  return mirror;
  
}

int main()
{
  char * mirror = (char*) malloc(sizeof(char));
  NULLCHECK(mirror);
  char word[255]="";
  scanf("%s",word);
  mirror = mirrored(word,mirror); 
  printf("%s",mirror);
  free(mirror);
}