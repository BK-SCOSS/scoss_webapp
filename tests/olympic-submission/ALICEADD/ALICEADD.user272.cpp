#include <bits/stdc++.h>
#define x first
#define y second
#define HANH ""
using namespace std;

void tinh(string a, string b)
{
    int nho=0, u;
    string kq="";
    while(a.size()<b.size()) a="0"+a;
    while(b.size()<a.size()) b="0"+b;
    for(int i=a.size()-1; i>=0; --i){
        u=(a[i]-'0')+(b[i]-'0')+nho;
        int luu=u%10;
        kq=char(luu+'0') + kq;
        nho=u/10;
    }
    if(nho!=0) kq=char(nho+'0')+kq;
    cout <<kq <<"\n";
}

int main()
{
    //freopen("".inp, "r", stdin);
    //freopen("".out, "w", stdout);
    int n;
    string a, b;
    cin >>n;
    for(int i=1; i<=n; ++i){
        cin >>a >>b;
        tinh(a, b);
    }
    return 0;
}
