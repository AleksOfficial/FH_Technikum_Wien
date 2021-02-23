#include <stdio.h>
#include <stdlib.h>
int gcd(int z1, int z2)
{
  int z3;
  if (z1 > z2)
  {
    z3 = z1 % z2;
  }
  else
  {
    z3 = z2 % z1;
  }
  if (z3 != 0)
  {
    return gcd(z2, z3);
  }
  else
  {
    return z2;
  }
}

int *eratosthenes(int amount)
{
  int savepoint;
  int *all_numbers = calloc(amount, sizeof(int));
  for (int i = 0; i < amount; i++)
  {
    if (i == 0)
      continue;
    else
    {
      if (all_numbers[i])
      {
        continue;
      }
      else
      {
        savepoint = i+1;
        for(int j=savepoint*2-1;j<amount;j=j+savepoint)
        {
          all_numbers[j]=1;
        }
      }
    }
  }
  all_numbers[0]=1;
  return all_numbers;
}

int main()
{ int len;
  printf(": ");
  scanf("%d",&len);
  int * prime;
  prime = eratosthenes(len);
  int j=0;  
  while(j<len)
  {
    for(int i=0;i<10;)
    {
      if(j==len)
        break;
      if(!prime[j])
      {
        printf("%d ",j+1);
        i++;
        j++;
      }
      else
      {
        j++;
        continue;
      }
    }
    printf("\n");
  }
  free(prime);
}