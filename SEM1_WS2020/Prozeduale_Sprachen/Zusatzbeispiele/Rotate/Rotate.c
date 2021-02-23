#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wl_element
{
  char word[100];
  struct wl_element *next;
};

struct wl_element *word_list = {0};

struct wl_element *create(char *text)
{
  //Erzeugt und retourniert einen neuen Listenknoten (ohne ihn einzuhängen!). Liefert `NULL` im Fehlerfall.
  struct wl_element *new = malloc(sizeof(struct wl_element));
  if(new == NULL)
    return NULL;
  strcpy(new->word, text);
  new->next = NULL;
  return new;
}

void attach_back(struct wl_element *element)
{
  //Fügt den übergebenen Knoten an das Ende der Liste an (es wird kein neuer erzeugt). Tut nichts, falls `knoten` auf `NULL` zeigt.
  struct wl_element *p;
  p = word_list;
  if (p == NULL)
  {
    word_list = element;
  }
  else
  {
    while (p->next != NULL)
    {
      p = p->next;
    }
    p->next = element;
  }
  
}

struct wl_element* new_node(char *text)
{
  struct wl_element * new = create(text);
  if(new == NULL)
    return NULL;
  attach_back(new);
  //Erzeugt und retourniert einen neuen Knoten und hängt diesen in die Liste ein. Retourniert `NULL` im Fehlerfall. (Hinweis: verwenden Sie `create()` und `attach_back()`)
  return new;
}

struct wl_element *detach_front()
{
  struct wl_element *p = word_list;
  if(p == NULL)
  {
    return NULL;
  }
  word_list = p->next;
  p->next = NULL;
  //Hängt den ersten Knoten der Liste aus und retourniert einen Zeiger darauf. Der Knoten wird NICHT freigegeben. Falls die Liste leer ist, wird `NULL` retourniert.
  return p;
}

void free_all()
{
  if(word_list != NULL)
  {
    struct wl_element * p, * np;
    p = word_list;
    while(p!=NULL)
    {
      np=p->next;
      free(p);
      p=np;
    }
  }
  //Löscht alle Elemente der Liste. `head` zeigt nachher auf `NULL`. Falls die Liste bereits leer ist, passiert nichts.
  word_list = NULL;
}

void rotate(int count)
{
  //Verschiebt den ersten Knoten an das Ende der Liste (Hinweis: verwenden Sie `detach_front()` und `attach_back()`)
  for(int i = 0; i<count;i++)
  {
    
    struct wl_element * p = detach_front();
    attach_back(p);
  }
  
}

void print()
{
  // Gibt alle Einträge der Liste aus (siehe Beispiel).
  struct wl_element * p = word_list;
  while(p!=NULL)
  {
    printf("%s\n",p->word);
    p=p->next;
  }
}

int main()
{
  char buffer[100];
  int rot;

  do
  {
    scanf("%99s", buffer);
  } while ((buffer[0] != '-') && (NULL != new_node(buffer)));

  print();
  scanf("%d", &rot);
  rotate(rot);
  print();

  free_all();

  return 0;
}