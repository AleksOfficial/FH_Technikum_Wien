#include <stdio.h>

void find_max(double *eingabe, double *max)
{
  if (*eingabe > *max)
  {
    *max = *eingabe;
  }
}

int main()
{
  double eingabe = 0.0, max = 0.0;
  while (42)
  {
    printf(": ");
    scanf("%lf", &eingabe);
    if (eingabe <= 0)
    {
      break;
    }
    else
    {
      find_max(&eingabe, &max);
    }
  }
  if (max <= 0)
  {
    printf("no numbers entered\n");
  }
  else
  {
    printf("largest number: %.2f", max);
  }
}