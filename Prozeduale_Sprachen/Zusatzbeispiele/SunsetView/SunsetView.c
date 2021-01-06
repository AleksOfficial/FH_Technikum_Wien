#include <stdio.h>
#include <stdlib.h>

typedef struct buildings
{
  int height;
  int index;
  struct buildings *next;
} buildings;

void free_all(buildings *list)
{
  buildings *p, *np;
  p = list;
  while (p != NULL)
  {
    np = p->next;
    free(p);
    p = NULL;
    p = np;
  }
}

buildings *create_building(int input, int index)
{
  buildings *new_building = malloc(sizeof(buildings));
  new_building->height = input;
  new_building->index = index;
  new_building->next = NULL;
  return new_building;
}

buildings *sunset_update(buildings *list, int input, int index)
{ int first = 0;
  int counter = 0;
  buildings *prev = list;
  buildings *p = list;
  if (p == NULL)
    return create_building(input, index);
  else
  {
    while (p != NULL)
    { counter++;
      if (p->height <= input)
        break;
      if (p->next == NULL)
      {
        p->next = create_building(input, index);
        return list;
      }
      p = p->next;
      
      if(first)
        prev = prev->next;
      if(!first)
        first = 1;
      
    }
    free_all(p);
    if(counter ==1)
      return create_building(input,index);
    prev->next = create_building(input,index);
  }
  return list;
}

void print(buildings *list)
{
  buildings *p = list;
  while (p != NULL)
  {
    printf("%d [%d] ", p->height, p->index);
    p = p->next;
  }
  printf("\n");
}

int main()
{
  //int sunsets[255][2] = {0};
  //int buildings[255][2] = {0};
  buildings *sunset = NULL;
  int input = -1;
  int index = 0;
  
  while (42)
  {
    printf(": ");
    scanf("%d", &input);
    if (input == 0)
      break;
    //new_entry(list,input,index);
    sunset = sunset_update(sunset, input, index);
    print(sunset);

    //perhaps this is easier with a linked list
    //altough I have to say that perhaps redoing the sort algorithms would probably be a good exercise...
    //turns out that a linked list wasn't as easy as I hoped it was. It was a super duper hard mistake to assume
    //that freeing a pointer and then setting it to NULL would change anything in other pointers as well. It doesn't. 
    //the list falls apart if the pointer is once set to NULL cuz all pointers that originally pointed ot that memory address
    //have nothing in common anymore. (DUH this address doesn't exist anymore...) which means that the next element in update points
    //on the FREE Pointer instead of NULL. also, p and the next aren't the same, therefore assigning any value to it (like NULL) would lead to nothing at all.
    //I had to save the previous element as well in order to have the new element be assigned to the next element of the list. 


    /*
    buildings[index][0]=input;
    buildings[index][1]=index;
    sunsets[index][0]=input;
    sunsets[index][1]=index;
    my_qsort(sunsets[0],sunsets[index]);
    */
    index++;
    //
  }
  print(sunset);
  free_all(sunset);
}