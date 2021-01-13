#include <bits/stdc++.h>

using namespace std;
unsigned long long Q,a[10000],T[10000];
int main()
{
    cin >> Q;
    for (int i=0; i<Q;++i){
        cin >> a[i];
        T[i]=a[i]*(a[i]+1)*(a[i]+2);
    }
    for (int i=0; i<Q;++i){
        int s=0;
        for(int j=1;j<1000000;++j){
        unsigned long long k=T[i]*T[i];
        if(k%j==0&&T[i]%j!=0&&j<T[i]) s+=1;
        }
        cout<<s<<endl;
    }
    return 0;
}
