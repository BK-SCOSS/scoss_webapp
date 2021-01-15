#include <bits/stdc++.h>
using namespace std;
int t;
string a,b;
vector <int> v1,v2,v3;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        v1.clear(); v2.clear();
        for (int i=a.size()-1;i>=0;--i)
        {
            v1.push_back(a[i]-'0');
        }
        for (int i=b.size()-1;i>=0;--i)
        {
            v2.push_back(b[i]-'0');
        }
        v3.clear();
        int l=max(v1.size(),v2.size());
        v1.resize(l);
        v2.resize(l);
        int e=0,tmp;
        for (int i=0;i<l;i++)
        {
            tmp=v1[i]+v2[i]+e;
            v3.push_back(tmp%10);
            e=tmp/10;
        }
        if (e>0) v3.push_back(e);
        l=v3.size();
        for (int i=l-1;i>=0;--i) cout << v3[i];
        cout << endl;
    }
}
