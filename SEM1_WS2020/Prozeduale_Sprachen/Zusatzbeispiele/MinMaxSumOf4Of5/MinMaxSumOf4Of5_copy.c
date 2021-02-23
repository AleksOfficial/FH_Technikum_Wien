//for some reason bubble sort didn't work :( oh well, guess its too inefficient. Onto the other approach: summing numbers
#include <stdio.h>
// I did it this way so I don't have to copypaste this function 5 times with the different if-conditions
int function_to_figure_min_out(int *i,int *n, int*summin, int * summax, int *min_max){
    if(*i==*n){
            if(*min_max) {
                *summax = *summax - *i;
                *i = *summin;
                *min_max = 0;
                return 1;
                }
            else if(!*min_max) {
                *summin = *summin - *i;
                return 0;
                }
    }
    else {
        return 1;
    }

return 0; // idk why but only with this it works. *control reaches end of non-void function [-Werror=return-type]* ?? Da sind 3 Return Statements
}


int main(){
    
    int n1,n2,n3,n4,n5, i = 0, summin=0, summax=0;
    printf(": ");
    scanf("%d %d %d %d %d",&n1, &n2, &n3, &n4, &n5);

    summax = n1 + n2 + n3 + n4 + n5;
    summin = summax;
    int min_max = 1,loop = 1; // this variable helps to switch between subtracting the min and max sum
    //finding out, which number is the smallest with a while loop
    //efficiency Big o = n
    // Basefunction:
    /* if(i==n1){
                if(min_max) {
                    summin = summin - n1;
                    i = summax;
                    min_max = 0;
                    }
                else if(!min_max) {
                    summax = summax - n1;
                    break;
                    } */

    while(loop){
       loop = function_to_figure_min_out(&i, &n1, &summin, &summax, &min_max);
       if(!loop) break;
       loop = function_to_figure_min_out(&i, &n2, &summin, &summax, &min_max);
       if(!loop) break;
       loop = function_to_figure_min_out(&i, &n3, &summin, &summax, &min_max);
       if(!loop) break;
       loop = function_to_figure_min_out(&i, &n4, &summin, &summax, &min_max);
       if(!loop) break;
       loop = function_to_figure_min_out(&i, &n5, &summin, &summax, &min_max);
       if(!loop) break;
       if(min_max)i++; else i--;
            
        }

    printf("minimum sum: %d\n", summin);
    printf("maximum sum: %d", summax);
    return 0;   
    }

   


