#include <stdio.h>

void smallest(int* n, int* m, int a[*n], int b[*m]){
	int x=0;
	int x2=0;
	int na=*n;
	int mb=*m;
	int h=0;
	for(int i=0; i<na; i++){
		for(int j=0; j<mb; j++){
			x2=a[i]-b[j]; // this is wrong unfortunately
			if(h==0 && x2>=0){
				x=x2;
			}
			else if(x2>=0 && x2<x){
				x=x2;
				*n=i;
				*m=j;
			}
		}
	}
	printf("%d (%d, %d)", x, a[*n], b[*m]);
}
	

int main(){
    
    int n=0;
    int m=0;
    printf(": ");
    scanf("%d", &n);
    scanf("%d", &m);
    int a[n];
    int b[m];
    printf(": ");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
		printf(": ");
    for(int j=0; j<m; j++){
        scanf("%d", &b[j]);
    }
    
	smallest(&n, &m, a, b);
	
	return 0;
	
}