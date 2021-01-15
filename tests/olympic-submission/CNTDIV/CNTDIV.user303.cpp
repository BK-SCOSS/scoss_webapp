#include <bits/stdc++.h>
using namespace std;
long long n,q,m,t1,t2;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> q;
    while (q--)
    {
        cin >> n;
        m=n*(n+1)*(n+2);
        t1=1;t2=1;
        for (int i=2;i<=n+2;i++)
        {
            int s=0;
            while (m%i==0)
            {
                m=m/i; s++;
            }
            t1=t1*(s+1);
            t2=t2*(2*s+1);
        }
        cout << (t2-2*t1+1)/2 << '\n';
    }
}
