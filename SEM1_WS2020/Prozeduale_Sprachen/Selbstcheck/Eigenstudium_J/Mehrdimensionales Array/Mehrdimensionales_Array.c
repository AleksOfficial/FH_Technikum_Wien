#include <stdio.h>

int main()
{

  int twodimensions[3][3];
  for(int i = 0; i<3;i++)
  {
    for(int j=0;j<3; j++)
    {
      twodimensions[i][j]=i+j;
      printf("%d\n",twodimensions[i][j]);
      
    }
  }
}