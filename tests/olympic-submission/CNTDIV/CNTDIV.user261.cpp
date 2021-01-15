#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1000007;
const long long C = 1000002;
long long pr[maxn], test;
long long nn[10];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    for (long long i=1; i<=C; ++i) pr[i]=i;
    for (long long i=2; i<=C; ++i)
        if (pr[i]==i)
            for (long long j=i*i; j<=C; j+=i){
                if (j<=C) pr[j]=i;
                //cout<<i<<" "<<j<<endl;
            }
    cin>>test;
    long long x, n, b, a, cnt=0, cnt2=0, _t, _z;
    while(test--){
        cin>>n;
        nn[1] = n;
        nn[2] = n+1;
        nn[3] = n+2;
        cnt2=0; b=1; a=1;
        for (int i=1; i<=3; ++i)
            while (nn[i]%2==0){
                nn[i]/=2;
                cnt2++;
            }
        //cout<<cnt2<<endl;
        b*=(2*cnt2+1);
        a*=(cnt2+1);
        //cout<<b<<" "<<a<<endl;
        for (int i=1; i<=3; ++i){
            cnt=0; _z=pr[nn[i]];
            while (nn[i]!=1){
                _t = pr[nn[i]];
                if (_t!=_z){
                    b*=(2*cnt+1);
                    a*=(cnt+1);
                    _z=_t;
                    cnt=0;
                }
                cnt++;
                nn[i]/=_t;
            }
            if (cnt>0){
                b*=(2*cnt+1);
                a*=(cnt+1);
            }
        }

        //cout<<b<<" "<<a<<endl;
        cout<<(b-2*a+1)/2<<endl;
    }
    return 0;
}

