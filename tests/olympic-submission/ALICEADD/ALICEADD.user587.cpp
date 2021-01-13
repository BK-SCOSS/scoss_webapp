#include<bits/stdc++.h>

using namespace std;

string cong(string a, string b)
{
    string rs="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int cr=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tg=a[i]-48 + b[i]-48 + cr;
        cr=tg/10;
        tg=tg%10;
        rs=(char)(tg+48)+rs;
    }
    if(cr>0) rs="1"+rs;
    return rs;
}

int main()
{
    int t;
    string a,b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << cong(a,b) << '\n';
    }
}
