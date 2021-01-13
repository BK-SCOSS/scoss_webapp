#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define int long long

string tong(string a,string b)
{
    while(a.length()<b.length()) a = "0" + a;
    while(b.length()<a.length()) b = "0" + b;
    string c = "";
    int nho = 0;
    for(int i=a.length()-1 ; i>=0 ; i--)
    {
        int sum = a[i] + b[i] - 48 - 48 + nho;
        nho = sum/10;
        c = char((sum%10) + 48) + c;
    }
    if (nho)
        c = "1" + c;
    return c;
}

main()
{
    int T;
    string a,b;
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        cout<<tong(a,b)<<'\n';
    }
}
