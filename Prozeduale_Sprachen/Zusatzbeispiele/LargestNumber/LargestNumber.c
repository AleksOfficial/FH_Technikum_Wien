#include <stdio.h>
#include <stdlib.h>

//meh. could have solved it way easier. without pointers. just check if the current number entered is larger than max, if yes, overwrite else no. if 0 ->
int main(){
    double eingabe = 0.0,max=0.0;
    double *zahlen;
    int size=1;

    zahlen =calloc(1,sizeof(double));
    if(zahlen==NULL){
        printf("Kein Speicher vorhanden!");
        exit -1;
    }
    while(42){
        printf(": ");
        scanf("%lf",&eingabe);
        if(eingabe<1)
        {
            if(size==1) // or check if size = 1? lets try that first
            {
                printf("no numbers entered");
                free(zahlen);
                break;
            }
            else
            {
                for(int i = 0;i<size;i++)
                {
                    if(max<zahlen[i])
                    {
                        max = zahlen[i];
                    }
                }
                printf("largest number: %.2f",max);
                free(zahlen);
                break;
            }
        }else
        {
            size++;
            zahlen=realloc(zahlen,size*sizeof(double));
            zahlen[size-1]=eingabe;
        }       
    }
    return 0;
}