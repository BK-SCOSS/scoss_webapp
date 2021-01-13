#include<bits/stdc++.h>
using namespace std;
void sum(string p, string q)
{
    vector<int>res;
    int s=0, i = p.size()-1,j=q.size()-1;
    while((i>=0) and (j>=0))
    {
        int x = (p[i]-'0') + (q[j]-'0') + s;
        res.push_back(x%10);
        s = x/10;
        i--;
        j--;
    }
    while(i>=0)
    {
        int x = (p[i]-'0') + s;
        res.push_back(x%10);
        s = x/10;
        i--;
    }
    while(j>=0)
    {
        int x = (q[j]-'0') + s;
        res.push_back(x%10);
        s = x/10;
        j--;
    }
    while(s)
    {
        res.push_back(s%10);
        s=s/10;
    }
    for(int k = res.size()-1; k>=0; k--)
    {
        cout<<res[k];
    }
    cout<<"\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a,b;
        cin >> a >> b;
        sum(a,b);
    }
    return 0;
}
