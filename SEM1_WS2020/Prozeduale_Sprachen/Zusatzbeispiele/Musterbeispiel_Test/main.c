#include <stdio.h>
#include <stdlib.h>



typedef struct list_element{
    int wert;
    int limit;
    struct list_element* next;
}list_element;

typedef struct start
{
    int deleted;
    double avg;
    list_element *beginning_list;
}start;

void print_menu()
{
    printf("Enter value and limit X/Y: \n");
}

void print_list(start * hello)
{
    list_element* element = hello->beginning_list;
    
    while(element != NULL)
    {
        printf("%d/%d ",element->wert,element->limit);
        element = element->next;
    }
    printf("\n");
}

list_element * element_erstellen(start* hello, int limit)
{
    list_element* neues_element = malloc(sizeof(list_element));
    neues_element->limit = limit;
    neues_element->wert = 0;
    neues_element->next = hello->beginning_list;
    return neues_element;
}   	
void anfang_einfuegen(start * hello, int wert, int limit)
{
    if(wert>limit || wert == 0)
    {
        return;
    }

    list_element * neues_element = element_erstellen(hello,limit);
    hello->beginning_list = neues_element;    

}

void liste_erhoehen(start* hello, int wert, int limit)
{
    if(wert>limit)
    {
        return;
    }
    list_element * element = hello->beginning_list;
    while(element != NULL)
    {
        element->wert+=wert;
        element = element->next;
    }
}

void loeschen(start * hello)
{
    list_element * element = hello->beginning_list;
    list_element * vorheriges = hello->beginning_list;
    list_element * naechstes = hello->beginning_list;
    int first = 1;
    while(element!=NULL)
    {
        if(first)
        {
            first = 0;
            element=element->next;
            //  1/15 -> NULL
            if(element!=NULL)
            {
                naechstes = element->next;
            }
            else
            {
                return;
            }
        }
        else
        {
            if(element->wert>element->limit)
            {
                vorheriges->next = naechstes;
                free(element);
                hello->deleted++;
                element = naechstes;
                if(element==NULL)
                {
                    return;
                }
                else
                {
                    naechstes = element->next;
                }
                
            }
            else
            {
                vorheriges = element;
                element = naechstes;
                if(naechstes != NULL)
                    naechstes = naechstes->next;
                else
                {
                    return;
                }
            }
        } 
    }
}

void calculate_avg(start * hello)
{
    int count = 0;
    double sum = 0;
    list_element * element = hello->beginning_list;
    while(element != NULL)
    {
        sum+=element->wert;
        count++;
        element = element->next;

    }
    hello->avg = sum / count;
}

void free_all(start*hello)
{
    list_element * element = hello->beginning_list;
    list_element * naechstes = element;
    while(element != NULL)
    {
        naechstes = element->next;
        free(element);
        element = naechstes;
    }
}

int main()
{
    int wert=1, limit;
    start hello = {0};
    while(wert!=0)
    {
        print_menu();
        scanf("%d/%d", &wert, &limit);
        
        anfang_einfuegen(&hello,wert,limit);
        liste_erhoehen(&hello,wert,limit);
        loeschen(&hello);
        print_list(&hello);
    }
    printf("Deleted: %d",hello.deleted);
    calculate_avg(&hello);
    printf("\nAVG    : %.2f",hello.avg);
    free_all(&hello);
    return 0;

}
