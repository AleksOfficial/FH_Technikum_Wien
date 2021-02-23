    /*Wenn die Punktezahl größer als 90 und kleiner gleich 100 ist, wird "Sehr gut" ausgegeben.
    Wenn die Punktezahl dann größer als 76 ist, wird "Gut" ausgegeben.
    Wenn die Punktezahl dann größer als 63 ist, wird "Befriedigend" ausgegeben.
    Wenn die Punktezahl dann größer gleich 50 ist, wird "Genuegend" ausgegeben.
    Wenn die Punktezahl dann kleiner als 50 und größer gleich 0 ist, wird "Nicht genuegend" ausgegeben.
    Ansonsten wird "Ungueltige Punktezahl" ausgegeben, wenn also die Punktezahl nicht im Bereich 0 - 100 liegt.*/
#include <stdio.h>

int main(){
    int Note = 0;
    scanf("%d",&Note);
    
    switch (Note)
    {
        case 1:
            printf("Sehr gut");
            break;
        case 2:
            printf("Gut");
            break;
        case 3:
            printf("Befriedigend");
            break;
        case 4:
            printf("Genuegend");
            break;
        case 5:
            printf("Nicht genuegend");
            break;
        default:
            printf("Ungueltige Note\n");
            break;
    }
   return 0;
}