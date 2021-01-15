#include <stdio.h>

int main(){
    int a,b, sum;
    int i=0;
    do{
        printf("");scanf("%d",a);
        printf("");scanf("%-2d",b);
        sum = a + b ;
        printf("%-10d",sum);
        i++;
    }
    while (i<=10);
    return 0;
}