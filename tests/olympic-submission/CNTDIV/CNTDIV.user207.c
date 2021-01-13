#include<stdio.h>

int main(){
    int n, N;
    scanf("%d", &n);
    for(int j=0; j<n; j++){
        scanf("%d", &N);
        int t = N*(N+1)*(N+2);
        int T = t*t;
        int count=0;
        for(int i=2; i<t; i++){
            if(T%i == 0 && t%i != 0)
                count++;
        }
        printf("%d", count);
    }    
    return 0;
}