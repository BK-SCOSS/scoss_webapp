#include<bits/stdc++.h>
const unsigned long long mn=1e19;
using namespace std;
string a,b;
int t;
string cong(string a,string b)
{
    int nho=0;
    while(a.size()<b.size())a='0'+a;
    while(a.size()>b.size())b='0'+b;
    int n=a.size();
    string res="";
    for(int i=n-1;i>=0;i--)
    {
        int tmp=a[i]+b[i]-96+nho;
        nho=tmp/10;
        res=(char)(tmp%10+48)+res;
    }
    if(nho==1)res='1'+res;
    return res;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("ALICEADD.inp","r",stdin);
    //freopen("ALICEADD.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<cong(a,b)<<'\n';
    }
    return 0;
}

