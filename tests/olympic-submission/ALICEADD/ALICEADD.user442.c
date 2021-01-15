#include<stdio.h>
#include<stdlib.h>

int main(){
    int T, D, a, b, *tong;
    tong = (int *) malloc(T * sizeof(int));
    scanf("%d", &T);
    D = T;
    while(T > 0){
        scanf("%d%d", &a, &b);
        tong[T - 1] = a + b; 
        T--;
    }
    for (int i = D - 1; i >= 0; i--)
    {
        printf("%d\n", tong[i]);
    }
}