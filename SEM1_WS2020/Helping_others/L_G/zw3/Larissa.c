#include <stdio.h>
#include <stdlib.h>

typedef struct class
{
    int stufe;
    char name;
    int pupilCounter;

    struct class *next;
} class;

typedef struct school
{
    struct class *classList;
    int jahre;
} school;

void printSchool(school *s)
{

    int tc = 0;
    int tp = 0;

    if (s->classList == NULL)
    {
        printf("\nSchool: no classes");
        return;
    }
    if (s->classList->next == NULL)
    {
        printf("\n%d%c - %d", s->classList->stufe, s->classList->name, s->classList->pupilCounter);
        tc++;
        tp = tp + s->classList->pupilCounter;
    }
    else
    {
        for (class *i = s->classList;;)
        {
            if (i == NULL)
                break;
            printf("\n%d%c - %d", i->stufe, i->name, i->pupilCounter);
            tc++;
            tp = tp + i->pupilCounter;
            i = i->next;
        }
    }

    printf("\nTotal: %d pupils - %d class(es)", tp, tc);
    printf("\nSchool is operating since %d year(s)", s->jahre);
}

void printYear(school *s)
{

    int year;
    int tp;
    int tc;

    printf("\nEnter a year (1-4):");
    scanf("%d", &year);

    if (s->classList == NULL)
    {
        printf("\nSchool: no classes");
        return;
    }
    for (class *i = s->classList;; i = i->next)
    {
        if (i == NULL)
            break;
        if (i->stufe == year)
        {
            printf("\n%d%c - %d", i->stufe, i->name, i->pupilCounter);
            tp += i->pupilCounter;
            tc++;
        }
    }
    if (tc == 0)
    {
        printf("\nNo such class");
        return;
    }
    printf("\nTotal: %d pupils - %d class(es)", tp, tc);
}

void printClass(school *s)
{
    int year;
    char index;
    int check = 0;
    printf("\nEnter a class (e.g.: 2B):");

    scanf("%d %c", &year, &index);
    if (s->classList == NULL)
    {
        printf("\nSchool: no classes");
        return;
    }

    for (class *i = s->classList;;)
    {
        if (i == NULL)
            break;
        if (i->stufe == year && i->name == index)
        {
            printf("\nClass %d%c has %d pupils", i->stufe, i->name, i->pupilCounter);
            check++;
        }
        i = i->next;
    }
    if (check == 0)
    {
        printf("\nNo such class");
    }
}

class * klasse_erstellen(int anzahl_schueler, char klassenname)
{

    class *neue_klasse = (struct class *)malloc(sizeof(struct class));
    neue_klasse->pupilCounter = anzahl_schueler;
    neue_klasse->name = klassenname;
    neue_klasse->stufe = 0;
    neue_klasse->next = NULL;
    return neue_klasse;
}

void einfuegen(school *s, int anzahl_schueler, char klassenname)
{

    class *neue_klasse = klasse_erstellen(anzahl_schueler, klassenname);
    if (s->classList != NULL)
    {
        neue_klasse->next = s->classList;
        s->classList = neue_klasse;
    }
    else
    {
        s->classList = neue_klasse;
    }
}

void stufeerhoehen(school *s)
{
    if (s->classList != NULL)
    {

        for (class *i = s->classList;; i = i->next)
        {
            i->stufe = i->stufe + 1;
            if (i->next == NULL)
            {
                break;
            }
        }
    }
}

void alle_freigeben(school * s)
{
    if(s->classList!=NULL)
    {
        class*tmp;
        class*p=s->classList;
        for(;p!=NULL;)
        {
            if(p->next!=NULL)
            {
                tmp=p->next;
            }
            else
            {
                tmp = NULL;
            }
            
            free(p);
            p=tmp;
        }
    }
}

void fuenfte_klassen_freigeben(school *s)
{ 
    class *p = s->classList;
    class*tmp;
    class * tmp2;
    if (p != NULL)
    {
        if (p->stufe == 5 && p->next == NULL)
        {
            free(p);
            s->classList = NULL;
        }
        else if (p->stufe == 5)
        {

            
            for(;p!=NULL;)
            {
                if(p->next!=NULL)
                {
                    tmp=p->next;
                }
                else
                {
                    tmp = NULL;
                }
                
                free(p);
                p=tmp;
                s->classList=NULL;
            }
        }
        else
        {

            for(;;)
            {

                if(p->next==NULL)
                    return;
                if(p->next->stufe==5)
                    break;
                p=p->next;
            }
            tmp=p;
            p=p->next;
            for(;;)
            {
                if(p==NULL)
                    break;
                if(p->next!=NULL)
                {
                    tmp2=p->next;
                }
                    
                else
                {
                    tmp2=NULL;
                }
                
                free(p);
                p=tmp2;
            }
            tmp->next=NULL;
            //1->2->3->4->5->5->NULL
            //1->3->5->NULL
            //1->2->3->4->NULL 
            
        }
    }
}

void neue_klasse(school *s)
{

    int students = 0;
    char n;

    printf("\nEnter number of students:");
    scanf("%d", &students);

    if (students < 15)
    {
        printf("Not enough students");
    }
    else if (students < 30)
    {
        n = 'A';

        einfuegen(s, students, n);
    }
    else if (students < 40)
    {
        int v = 0;
        int v2 = 0;
        if (students % 2 == 0)
        {
            v = students / 2;
            n = 'B';
            einfuegen(s, v, n);
            n = 'A';
            einfuegen(s, v, n);
        }
        else if (students % 2 == 1)
        {
            v = students / 2;
            v2 = v + 1;
            n = 'B';
            einfuegen(s, v, n);
            n = 'A';
            einfuegen(s, v2, n);
        }
    }
    else
    {
        int i;
        for (i = 26; i != 2; i--)
        {
            if (students / i >= 20)
            {
                break;
            }
        }
        int h =(students % i);
        int v = students / i;
        for (int k = i - 1; k >= h; k--)
        {
            n = 'A' + k;
            einfuegen(s, v, n);
        }
        for (int j = h - 1; j >= 0; j--)
        {
            n = 'A' + j;
            einfuegen(s, v + 1, n);
        }
    }
    stufeerhoehen(s);
    fuenfte_klassen_freigeben(s);
}

int main()
{

    school s = {0};
    char m;
    for (int i = 0;; i++)
    {
        printf("\nChoose action: school (s), year(y), class (c), new (n), exit (x):");
        scanf(" %c", &m);
        if (m == 'x')
        {
            break;
        }
        else if (m == 's')
        {
            printSchool(&s);
        }
        else if (m == 'y')
        {
            printYear(&s);
        }
        else if (m == 'c')
        {
            printClass(&s);
        }
        else if (m == 'n')
        {
            s.jahre++;
            neue_klasse(&s);
        }
        else
        {
            printf("\nInvalid selection");
        }
    }
    alle_freigeben(&s);
    return 0;
}
