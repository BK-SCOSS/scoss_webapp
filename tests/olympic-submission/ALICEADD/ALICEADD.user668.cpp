#include <bits/stdc++.h>
#define lo long long
#define KKH "BIGPLUS"
using namespace std;
string cong(string a,string b)
{
    if (a.size()<b.size()) swap(a,b);
    while (a.size()>b.size()) b='0'+b;
    int s,nho=0;
    string kq="";
    for (int i=b.size();i>=0;i--)
    {
        s=a[i]+b[i]-'0'-'0'+nho;
        nho=0;
        if (s>9) {nho=1;s-=10;}
        kq=char(s+48)+kq;
    }if (nho==1) kq='1'+kq;
    kq.erase(kq.size()-1,1);
    return kq;
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        string x,y;
        cin>>x>>y;
        cout<<cong(x,y)<<'\n';
    }
}
