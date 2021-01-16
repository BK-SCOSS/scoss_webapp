#include <bits/stdc++.h>

using namespace std;
int n,a[10000000];
long long int res,ma;

int main()
{
    int test;
    scanf("%d",&test);
    while(test--){
            res=0;
        scanf("%d",&n);;
        for(int i = 1 ; i <= n; i++){
            scanf("%d",&a[i]);
        }
    for(;;){
        if(n==1) break;
        ma = 0;
        long long int tg;
        for(int i = 1; i <= n/2+n%2;i++){
            if(i*2>n) tg=a[i*2-1];
            else tg=a[i*2-1]+a[i*2];
            ma =max(ma,tg);
            a[i]=tg;
            }
        n=n/2+n%2;
        res+=ma;
        }
    cout<< res;
    return 0;
    }
}
