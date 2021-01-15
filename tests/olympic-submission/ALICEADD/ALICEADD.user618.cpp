#include <bits/stdc++.h>
#define fto(i, a, b)  for (int i=a; i<=b; i++)
using namespace std;

string add(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}
int main()
{
    int t;
    string a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << add(a, b) << '\n';
    }
    return 0;
}
