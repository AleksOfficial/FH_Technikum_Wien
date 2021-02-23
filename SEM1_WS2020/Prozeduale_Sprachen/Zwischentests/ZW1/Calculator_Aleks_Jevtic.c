#include <stdio.h>
//Operationen
int addition(int zahl1, int zahl2)
{
  return zahl1 + zahl2;
}
int subtraction(int zahl1, int zahl2)
{
  return zahl1 - zahl2;
}
int multiplication(int zahl1, int zahl2)
{
  return zahl1 * zahl2;
}
int division(int zahl1, int zahl2)
{
  return zahl1 / zahl2;
}
int modulo(int zahl1, int zahl2)
{
  return zahl1 % zahl2;
}
//checks & choices
int valid_operation_division(int ergebnis, int eingabe)
{

  if (eingabe != 0) //Keine Division durch 0
  {
    if (ergebnis % eingabe == 0) // Kein Rest?
    {
      return 1;
    }
  }
  return 0;
}
int not_valid_operation(int ergebnis, int eingabe)
{
  int check = ergebnis - eingabe;
  if (check == 1 || check == (-1))
  {
    printf("Einer der Operanden ist um 1 kleiner oder groesser als der andere\n");
    return 1;
  }
  return 0;
}
char choose_option(int ergebnis, int eingabe)
{

  printf("Operation ist ungueltig!\n");
  if (eingabe == 0) //Fehler: Division durch 0
  {
    printf("Keine Divisionen durch 0!\n");
    return 'x'; //bei x bleibt das Ergebnis unverändert
  }
  else // Fehler: Division hat Rest
  {
    char choice;
    int quotient, rest;
    rest = modulo(ergebnis, eingabe);
    quotient = division(ergebnis, eingabe);
    printf("Ergebnis ist %d mit %d Rest. Soll gerundet (r), abgeschnitten (c) oder verworfen (x) werden?\n", quotient, rest);
    scanf(" %c", &choice);
    return choice;
  }
}

int main()
{
  int ergebnis, anzahl = 0, fehler = 0, eingabe = 0;
  char operator, choice = 0;

  //Ergebnis wird anfangs definiert
  scanf("%d", &ergebnis);

  do
  {

    scanf(" %c", &operator);
    if (operator!= 'x')
    {
      scanf("%d", &eingabe);
      if (not_valid_operation(ergebnis, eingabe)) //Fehlercheck: Operand um 1 groesser/kleiner
      {
        fehler++;
      }
      else
      {
        switch (operator)
        {
        case '+':
          ergebnis = addition(ergebnis, eingabe);
          anzahl++;
          break;
        case '-':
          ergebnis = subtraction(ergebnis, eingabe);
          anzahl++;
          break;
        case '*':
          ergebnis = multiplication(ergebnis, eingabe);
          anzahl++;
          break;
        case '/':
          if (valid_operation_division(ergebnis, eingabe))
          {
            anzahl++;
            ergebnis = division(ergebnis, eingabe);
          }
          else
          {
            fehler++;
            choice = choose_option(ergebnis, eingabe);
            switch (choice)
            {
            case 'r':
              if (modulo(ergebnis, eingabe) > (eingabe / 2)) //Aufrunden der Divison
              {
                ergebnis = (division(ergebnis, eingabe) + 1);
              }
              else
              {
                ergebnis = division(ergebnis, eingabe);
              }
              fehler--; //weil anfangs Fehler erhöht wurde, muss er um eins reduziert werden und Anzahl um 1 erhöht werden
              anzahl++;
              break;
            case 'c':
              ergebnis = division(ergebnis, eingabe);
              fehler--; //weil anfangs Fehler erhöht wurde, muss er um eins reduziert werden und Anzahl um 1 erhöht werden
              anzahl++;
              break;
            case 'x':
              break;
            }
          }
          break;
        }
      }
      printf("Ergebnis: %d\n", ergebnis);
    }
    else
    {
      break;
    }

  } while (42);
  printf("Programm wird beendet. Es wurden %d gueltige Operationen und %d ungueltige Operationen durchgefuehrt.", anzahl, fehler);
  return 0;
}