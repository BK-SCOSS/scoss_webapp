#include <stdio.h>

int main(){
	
	
    int a,b,sum;
    int i=1;
	int T;
	
	
    printf("\nso lan tinh");scanf("%d",&T);
    while(0>=T && T>10){
    printf("\nnhap so lan tinh nho hon hoac bang 10");
    printf("\nso lan tinh");scanf("%d",&T);
    }
    
    
    do{
        printf("");scanf("%d",&a);
        printf("");scanf("%d",&b);
        sum = a + b ;
        printf("%d",sum);
        printf("\n");
        i++;
    }
    while (i<=10);
    
    return 0;
}
