#include<bits/stdc++.h>

using namespace std;
long long q,n,tmp,r,res,can;
set <long long> kt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>q;
    for (long long z=0;z<q;z++)
    {
        cin>>n;
        if (n==1){cout<<0;continue;}
        tmp=n*(n+1)*(n+2),can=0,r=tmp*tmp,res=0;
        for (long long i=1;i*i<=tmp;i++)
        {
            if (tmp%i==0)
            {
                kt.insert(tmp/i);
            }
            can=i;
        }
        for (long long v=can+1;v<tmp;v++)
        {
            if ((r%v==0)&&(kt.count(v)==0)) {res++;}
        }
        cout<<res<<endl;
        kt.clear();
    }
    return 0;
}