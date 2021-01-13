/*#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        long long a,b;
        cin >> a  >> b;
        cout << a+b;
        cout << '\n';
    }
    return 0;
}*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
string add(string a, string b)
{
    string s="";
    while(a.length() < b.length()) a = "0" + a;
    while(b.length() < a.length()) b = "0" + b;
    int x=0;
    for(int i = a.length()-1; i >= 0; i--)
    {
        int tg = a[i]-48 + b[i]-48 + x;
        x= tg / 10;
        tg = tg % 10;
        s = (char)( tg + 48 )+ s;
    }
    if(x > 0) s = "1" + s;
    return s;
}
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string a,b;
        cin >> a  >> b;
        //cout << a << " " << b << '\n';
        cout << add(a,b);
        cout << '\n';
    }
    return 0;
}
