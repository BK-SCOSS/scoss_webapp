#include<bits/stdc++.h>
using namespace std;

int t;
string a,b;

void Solve()
{
    cin>>a>>b;

    string c="";

    if(a.length()<b.length())swap(a,b);

    if(a.length()>b.length())
        for(int i=0;i<=a.length()-b.length();++i)b="0"+b;

    int du=0;
    for(int i=a.length()-1;i>=0;--i)
    {
        int num1=a[i]-'0';
        int num2=b[i]-'0';

        int num=num1+num2+du;

        if(num>=10)
        {
            du=1;
            num%=10;
        }

        c=(char)(num+'0')+c;
    }
    if(du==1)c='1'+c;
    cout<<c<<'\n';
}

int main()
{
    cin>>t;
    while(t--)Solve();
}
