
#include<stdio.h>
int main(){
    int T;
    unsigned long long a,b;
        scanf("%llu",&T);
    int i=0;
    for( i=0;i<T;i++){
        scanf("%llu %llu",&a,&b);
        printf("%llu\n ",a+b);
    }

    }