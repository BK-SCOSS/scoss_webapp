#include <iostream>
#include <bits/stdc++.h>
#define forinc(i, a, b) for(int i =a,_b=b;i<=_b;i++)
#define fordec(i, a, b) for(int i =a,_b=b;i>=_b;i--)

using namespace std;

string add(string a, string b)
{
    string e=""; int nho=0;
    while (a.length() < b.length())
    {
        a='0' + a;
    }
    while (a.length() > b.length())
    {
        b='0' + b;
    }
    fordec(i, a.length(), 1)
    {
        if (a[i-1]-48-48 + b[i-1] + nho >= 10)
        {
            int c = a[i-1]-48;
            int d = b[i-1]-48;
            char tg=c+d+nho-10+48;
            e=tg+e;
            nho=1;
        }
        else
        {
            int c = a[i-1]-48;
            int d = b[i-1]-48;
            char tg=c+d+nho+48;
            e=tg+e;
            nho=0;
        }
    }
    if (nho == 1) e="1"+e;
    return e;
}

int main()
{
    int n;
    string a[11],b[11];

    cin >> n;
    forinc(i, 1, n)
    {
        cin >> a[i] >> b[i];
    }
    forinc(i, 1, n)
    {
        cout << add(a[i], b[i]) << endl;
    }

    return 0;
}
