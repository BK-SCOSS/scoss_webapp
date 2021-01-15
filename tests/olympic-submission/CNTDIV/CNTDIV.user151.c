#include<stdio.h>
#include<stdlib.h>
long long dem(long long N)
{
    long long T;
    long long i, S=0;
    T=N*(N+1)*(N+2);
    for(i=1;i<T;i++)
    {
        if(((T*T)%i==0)&&(T%i!=0))
        {
            S++;
        }
    }
    return S;
}
int main()
{
    long long j;
    long long Q;
    long long *a;
    scanf("%ld",&Q);
    a=(long long*)malloc(Q*sizeof(long long));
    for(j=0;j<Q;j++)
    {
        scanf("%ld",a+j);
    }
    for(j=0;j<Q;j++)
    {
        printf("%ld \n",dem(*(a+j)));
    }
    free(a); 
}