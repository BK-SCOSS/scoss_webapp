#include<stdio.h>

int main(){
    int Q;
    do scanf("%d",&Q);
    while( Q<=0);
    unsigned int N[100];
    unsigned long T[100];
    int d[100];
    for( int i= 1; i<=Q; i++ ){
        scanf("%d", &N[i]);
        T[i]=N[i]*(N[i]+1)*(N[i]+2);
        d[i]=0;
        for (int j =1; j<T[i];j++){
            if( T[i]*T[i]%j==0 && T[i]%j!=0) d[i]+=1;
        }
    }
    for (int i=1; i<=Q; i++) printf("%d\n", d[i]);
    return 0;
}

