#include <stdio.h>
#define N 10
typedef struct ant
{
  int position_x;
  int position_y;
  int direction;
  int dead;
}ant;

int main()
{
  ant new_ant ={0};

  char field[N][N];
  for(int i = 0; i<N;i++)
    for(int j = 0; j<N;j++)
      field[i][j] ='.';
  int turns = 0;
  new_ant.dead = 0;
  new_ant.direction = 3; //0=North,1=East,2=South,3=West
  printf("Number of turns: ");
  scanf("%d", &turns);
  printf("Start position: ");
  scanf("%d %d", &new_ant.position_x,&new_ant.position_y);
  while(42)
  {
    if(new_ant.position_x<0 || new_ant.position_x==N)
      {
        new_ant.dead = 1;
        break;
      }
    if(new_ant.position_y<0 || new_ant.position_y==N)
      {
        new_ant.dead = 1;
        break;
      }
    if(turns == 0)
      break;
    if(field[new_ant.position_x][new_ant.position_y]=='.')
      { 
        field[new_ant.position_x][new_ant.position_y]='#';
        new_ant.direction++;
        new_ant.direction= new_ant.direction%4;
        
        
      }
    else
    {
        field[new_ant.position_x][new_ant.position_y]='.';
        new_ant.direction--;
        if(new_ant.direction<0)
          new_ant.direction+=4;
        
    }
    switch(new_ant.direction)
    {
      case 0:
        new_ant.position_y--;
        break;
      case 1:
        new_ant.position_x++;
        break;
      case 2:
        new_ant.position_y++;
        break;
      case 3:
        new_ant.position_x--;
        break;
    }

    turns--;
  }
  if(!new_ant.dead)
  {
    if(field[new_ant.position_x][new_ant.position_y]=='.')
      field[new_ant.position_x][new_ant.position_y] = 'a';
    else
      field[new_ant.position_x][new_ant.position_y] = 'A';
  }
    
  for(int i = 0; i<N;i++)
    {
      for(int j = 0; j<N;j++)
        printf("%c",field[j][i]);
      printf("\n");
    }
    
}
