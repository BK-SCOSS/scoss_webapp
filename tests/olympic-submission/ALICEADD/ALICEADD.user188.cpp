#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{    int i,N;
     int c,d;
    long long a,b;
    long long S[12];
    int key[12];
    scanf("%d\n",&N);
    for(int i=1;i<=N;i++){
            scanf("%lld %lld",&a,&b);
        S[i]=a+b;key[i]=0;
        if(S[i]<0) { key[i]=1;
            c=a/pow(10,18);
            d=a/pow(10,18);
        S[i]=a-c*(pow(10,18))+b-d*pow(10,18)+((c+d)%10)*pow(10,18);
        }
    }
     for(int i=1;i<=N;i++)
     if(key[i]==0) printf("%lld\n",S[i]);
     else printf("1%lld\n",S[i]);
    return 0;
}

