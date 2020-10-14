#include <stdio.h>
#include <stdbool.h>

int main()
{
    int zahl1, zahl2, erg, validCounter = 0, invalidCounter = 0;
    char op = ' ', makeThis;

    printf("Bitte geben Sie die erste Zahl ein");
    scanf("%d", &zahl1);


    while(true)
    {
        erg = zahl1;
        printf("Bitte geben Sie einen Operator ein");
        scanf("%s", &op);
        if (op == 'x'){
            break;
        }

        printf("Bitte geben Sie die zweite Zahl ein");
        scanf("%d",&zahl2);
        if ((zahl2 == zahl1+1) || (zahl2 == zahl1-1)) //prüfen der 2. Zahl (um 1 größer oder kleiner?)
        {
            invalidCounter++; //wird um 1 erhöht, wenn Operation ungültig
            printf("Einer der Operanden ist um 1 kleiner oder groesser als der andere\n");
        } else {

            switch (op) {
                case '+':
                    erg = zahl1 + zahl2;
                    validCounter++; //wird um 1 erhöht, wenn Operation gültig
                    break;
                case '-':
                    erg = zahl1 - zahl2;
                    validCounter++;
                    break;
                case '*':
                    erg = zahl1 * zahl2;
                    validCounter++;
                    break;
                case '/':
                    if (zahl2 == 0) { //fehler bei division durch 0
                        invalidCounter++;
                        printf("Operation ist ungueltig!\n");
                        printf("Keine Divisionen durch 0!\n");
                        erg = zahl1; //damit bei mit zahl1 gerechnet werden kann
                    } else {
                        int  mod = zahl1%zahl2; //für effizienz
                        int division = zahl1/zahl2; //für effizienz
                        if(mod !=0){//rest vorhanden?
                            printf("Operation ist ungueltig!\n");
                            printf("Ergebnis ist %d mit %d Rest. Soll gerundet (r), abgeschnitten (c) oder verworfen (x) werden?\n",division, mod);
                            scanf("%s", &makeThis);

                            switch(makeThis) {
                                case 'r':
                                    if (mod > zahl2/2)
                                    {
                                        erg = division + 1;
                                    }
                                    else {
                                        erg = division;
                                    }
                                    validCounter++;
                                    break;
                                case 'c':
                                    erg = ((zahl1-mod)/zahl2);
                                    validCounter++;
                                    break;
                                case 'x':
                                    invalidCounter++;
                                    break;
                            }
                        }else {
                            if(mod > 0 || zahl2 != 0)
                                erg=division;
                            validCounter++;
                        }

                    }


            }
        }
        zahl1 = erg; //damit mit dem Ergebnis weiter gerechnet werden kann
        printf("Ergebnis: %d\n", erg);

    }
    printf("Programm wird beendet. Es wurden %d gueltige Operationen und %d ungueltige Operationen durchgefuehrt.\n", validCounter, invalidCounter);
return 0;
}