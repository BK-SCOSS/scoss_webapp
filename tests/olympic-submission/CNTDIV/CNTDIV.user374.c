
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Q;
    int T,N;
    scanf("%d", &Q);
    for(int i=0;i<Q;i++){
        scanf("%d", &N);
        T = N*(N+1)*(N+2);
        int count=0;
        for(int j=1;j<T;j++){
            if(T*T%j==0&&T%j!=0){
                count++;
            }
        }
        printf("%d", count);
    }
    return 0;
}
