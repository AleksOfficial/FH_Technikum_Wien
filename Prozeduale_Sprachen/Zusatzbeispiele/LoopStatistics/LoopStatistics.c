#include <stdio.h>

struct stats
{
  int count;
  double min;
  double max;
  double sum;
};

void input(struct stats *x, double _input)
{
  x->count++;
  if (_input < x->min||x->min ==0)
  {
    x->min = _input;
  }
  if (_input>x->max)
  {
    x->max = _input;
  }
  x->sum+=_input;
}

int main()
{
  struct stats my_stats = {0, 0, 0, 0};
  double _input =0;
  int check=0;
  while(42)
  {
    printf(": ");
    scanf("%lf", &_input);
    if (_input <= 0)
    {
      break;
    }
    else
    {
      check =1;
      input(&my_stats, _input);
    }
  }
  if (check){
  printf("cnt: %d\n",my_stats.count);
  printf("min: %.2f\n",my_stats.min);
  printf("max: %.2f\n",my_stats.max);
  printf("avg: %.2f\n",(my_stats.sum/my_stats.count));
  }
  else
  {
    printf("no number entered");
  }
  
}