#include "stdio.h"

int nUC(int T){
    int T2, m=0;
    T2 = T*T;
    for (int i = 1; i < T; i++)
    {
        if (T2 % i == 0){
            if(T % i != 0){
            m++;
            }
        }
    }
    return m;
}

int main(){
    int n, N, T, result;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &N);
        T = N*(N+1)*(N+2);
        printf("%d\n", nUC(T));
    }
    return 0;
}