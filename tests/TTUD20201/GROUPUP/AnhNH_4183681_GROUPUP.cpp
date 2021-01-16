#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int t, n, a[N],res,ii,maxx;

int getInput(){

    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];

    return 0;
}

int process(){

    res = 0;

    while(n > 1){
        ii = 1;
        maxx = 0;
        while(2 * ii <= n){
            a[ii] = a[2 * ii - 1] + a[2 * ii];
            maxx = max(maxx, a[ii]);
            ii++;
        }
        if(n % 2 == 1){
            a[ii] = a[n];
            maxx = max(a[ii], maxx);
        } else ii -= 1;
        res += maxx;
        n = ii;
    }

    cout<<res<<'\n';
    return 0;
}

int main(){
    //freopen("test.inp", "r", stdin);
    cin>>t;
    while(t){
        t--;

        getInput();
        //cout<<1<<'\n';
        process();
    }
    return 0;
}

