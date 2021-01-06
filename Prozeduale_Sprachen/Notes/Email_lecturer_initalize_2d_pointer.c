#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 5

int main()
{
    char** data;

    //Speicher beanspruchen
    data = malloc(ROWS * sizeof(*data));
    for (int n = 0; n < ROWS; ++n)
    {
        data[n] = malloc(COLUMNS * sizeof(data[0])); // this has to change to sizeof(char)+1 so that it is the most efficient; otherwise you reserve way more memory than needed
    }

    //Werte eintragen
    for(int n=0; n < ROWS; ++n)
    {
        for(int m=0; m<COLUMNS; ++m)
        {
            data[n][m] = '.';
        }
    }

    //Werte ausgeben
    for(int n=0; n < ROWS; ++n)
    {
        for(int m=0; m<COLUMNS; ++m)
        {
            printf("%c", data[n][m]);
        }
        printf("\n");
    }

    //Speicher freigeben
    for (int n = 0; n < ROWS; ++n)
    {
        free(data[n]);
    }
    free(data);

    return 0;
}

