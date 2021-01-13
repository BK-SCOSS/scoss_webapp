#include<stdio.h>
#include<math.h>
int main(){
    int n,N,T,d = 0;
    scanf("%d",&n);
    scanf("%d",&N);
    T = N*(N+1)*(N+2);
    for (int i=1;i<T;i++){
        if (((T*T) % i == 0) && (T % i != 0)){
            d += 1;
        }
    }
    printf("%d",d);
    return 0;

}