#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct exam_element
{
  char name[21];
  int points;
  struct exam_element *next;
}exam_element;

typedef struct hello_world
{
  double avg;
  double avg_pos;
  int count_pos;
  int count_neg;
  int total_points;
  int total_points_pos;
  double percentage_pos;
  struct exam_element *beginning_element;
  

}hello_world;

exam_element* create_element(int points, char* name)
{
  exam_element * new_element = malloc(sizeof(exam_element));
  new_element->points = points;
  strcpy(new_element->name,name);
  new_element->next = NULL;
  return new_element;
}

void set_next_element(hello_world*hello,int points, exam_element * new_element)
{
  exam_element * element = hello->beginning_element;
  exam_element * prev = hello->beginning_element;
  int first = 1;
  while(element != NULL)
  {
    if(first)
    {
      element = element->next;
      first = 0;
      if(element == NULL)
      {
        if(prev->points<points)
        {
          new_element->next = element;
          prev->next = new_element;
          break;
        }
        else
        {
          new_element->next = prev;
          hello->beginning_element = new_element;
          break;
        }
      }
      else
      {
        if(prev->points>points)
        {
          new_element->next = prev;
          hello->beginning_element = new_element;
        }
      }
    }
    if(element->points>points)
    {
      new_element->next = element;
      prev->next = new_element;
      break;
    }
    else if(element == NULL)
    {
      prev->next = new_element;
      break;
    }
    prev = element;
    element = element->next;
    

  }
}

void add_exam(hello_world * hello, int points, char* name)
{
  exam_element * element = create_element(points,name);
  if(points<50)
  {
    hello->total_points+=points;
    hello->count_neg++;
  }
  else
  {
    hello->total_points+=points;
    hello->total_points_pos+=points;
    hello->count_pos++;
  }
  
  if(hello->beginning_element == NULL)
  {
    hello->beginning_element = element;
  }
  else
  {
    set_next_element(hello,points,element);
  }
  
}
  
void print_list(hello_world* hello) // ah deswegen from und to, damit mans in stats wiederverwenden kann lel. 
{
  exam_element* element = hello->beginning_element;
  printf("\n");
  while(element!=NULL)
  {
    printf("%s %d->",element->name, element->points);
    element = element->next;
  }
}
/*
  hello->avg = calculate_avg(hello);
  hello->percentage_pos = calc_percentage_pos(hello);
  hello->avg_pos = calculate_avg_pos(hello);
*/
double calculate_avg(hello_world * hello)
{
  double total_points = hello->total_points;
  return total_points/(hello->count_neg+hello->count_pos);
}
double percentage_pos(hello_world * hello)
{
  double total_amount = hello->count_neg+hello->count_pos;
  return total_amount/hello->count_pos*100;
}
double calculate_avg_pos(hello_world * hello)
{
  double total_points = hello->total_points_pos;
  return total_points/hello->count_pos;
}
void print_stats(hello_world* hello)
{
  int sum = 0;
  int sum_pos = 0;
  printf("\nNEG list: ");
  exam_element * element = hello->beginning_element;
  while(element != NULL)
  {
    if(element->points >= 50)
    {
      break;
    }
    printf("%s %d->",element->name,element->points);
    sum+=element->points;
    element = element->next;
  }  
  printf("\nPOS list: ");
  while(element != NULL)
  {
    printf("%s %d->",element->name,element->points);
    sum+=element->points;
    sum_pos+=element->points;
  }
  hello->avg = calculate_avg(hello);
  hello->percentage_pos = percentage_pos(hello);
  hello->avg_pos = calculate_avg_pos(hello);
  printf("\nAVG points: %.2f",hello->avg);
  printf("\nPOS: %d",hello->count_pos);
  printf("\nNEG: %d",hello->count_neg);
  printf("\npercentage POS: %.2f",hello->percentage_pos);
  printf("\nAVG points POS: %.2f",hello->avg_pos);

}
void free_all(hello_world * hello)
{
  exam_element * element = hello->beginning_element;
  exam_element * _next = hello->beginning_element;
  while(element!=NULL)
  {
    _next = element->next;
    free(element);
    element = _next;
  }
}

int main()
{

  hello_world hello = {0};
  int points;
  char name[21];
  while(1)
  {
    printf("\nnew exam: ");
    scanf("%d,%20s",&points,name);
    if(points < 0)
    {
      break;
    }
    add_exam(&hello,points,name);
    print_list(&hello);
  }
  print_list(&hello);
  print_stats(&hello);
  free_all(&hello);
}
