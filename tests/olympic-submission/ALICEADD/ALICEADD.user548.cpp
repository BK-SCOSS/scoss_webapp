#include<bits/stdc++.h>

using namespace std;

string congSL(string a,string b){
    string c="";
    int nho=0,tong;
    while(a.size()<b.size()) a="0"+a;
    while(b.size()<a.size()) b="0"+b;
    for(int i=a.size()-1;i>=0;i--){
        tong=a[i]+b[i]-96+nho;
        nho=tong/10;
        tong=tong%10;
        c=char(tong+48)+c;
    }
    if(nho) c="1"+c;
    return c;
}

main()
{
    //freopen("ALICEADD.inp","r",stdin);
    //freopen("ALICEADD.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        //unsigned long long a,b;
        cin>>a>>b;
        cout<<congSL(a,b)<<'\n';
        //cout<<a+b<<'\n';
    }
}
