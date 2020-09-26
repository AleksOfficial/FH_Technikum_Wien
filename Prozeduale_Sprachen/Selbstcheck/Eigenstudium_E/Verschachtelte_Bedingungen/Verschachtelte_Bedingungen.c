#include <stdio.h>

int main(){
    int punkte = 0;
    scanf("%d",&punkte);
    if(punkte>0 && punkte<101)
    {
        //printf("Gültige Punktezahl\n");
        if(punkte>49)
        {
            printf("Positive Note");
        }
        else
        {
            printf("Negative Note");
        }
        return 0;
        
    }
    
    return -1;
}