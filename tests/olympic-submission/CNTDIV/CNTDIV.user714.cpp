#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("CNTDIV.INP","r",stdin);
    //freopen("CNTDIV.OUT","w",stdout);
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int n; cin >> n;
        long t=n*(n+1)*(n+2);
        int cnt=0;
        for (long i=1; i<t; i++) if (round(t*t/i)==t*t*1.0/i) {/*cout << i << ' ';*/ cnt++;} //cout << '\n';
        for (long i=1; i<=sqrt(t); i++) if (round(t/i)==t*1.0/i) {/*cout << i << ' ';*/ cnt-=(i*i==t || i==1 ? 1 : 2);} //cout << '\n';
        cout << cnt << '\n';
    }
    return 0;
}
