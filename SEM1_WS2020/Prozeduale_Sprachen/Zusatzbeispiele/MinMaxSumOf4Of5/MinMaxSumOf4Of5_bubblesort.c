#include <stdio.h>

int bubble_sort(int * n1, int * n2){
    int temp = 0;
    if(*n1>=*n2){
        temp = *n1;
        *n1 = *n2;
        *n2 = temp;
        return 1;
    }
    else return 0;
            
        }



int main(){
    
    int n1,n2,n3,n4,n5, summin=0, summax=0;
    printf(": ");
    scanf("%d %d %d %d %d",&n1, &n2, &n3, &n4, &n5);
    int sort_check = 0;

    //I'll sort the numbers from 1-5 so that the far right number is the highest (n5) and n1 is the smallest.
    //the min sum is then sum(n1-n4) and max is sum(n2-n5)
    //I guess Arrays aren't allowed? that's why bubble sort
    //bubble_sort is a helperfunction, that compares 2 numbers and swaps their place if the first number is larger than the first one
    // you could solve that also with a large code containing if conditions over if conditions, but this way it's cleaner. big O = n². could be more efficient. 
    //maybe figuring out, which number is the smallest/largest, and then calculating the sum? I'll do both approaches :)  
    int i = 1;
    while(i>=1){
        //Bubble Sort works :)
        i = 1;
        i = i + bubble_sort(&n1,&n2);
        i = i + bubble_sort(&n2,&n3);
        i = i + bubble_sort(&n3,&n4);
        i = i + bubble_sort(&n4,&n5);
        if(i == 1) break;

        

    }
    summin = n1 + n2 + n3 + n4;
    summax = n5 + n2 + n3 + n4; 
    printf("minimum sum: %d\n", summin);
    printf("maximum sum: %d", summax);


}