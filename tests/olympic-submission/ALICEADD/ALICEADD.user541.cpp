#include <bits/stdc++.h>

using namespace std;

int t;
string a, b;

string add(string a, string b)
{
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    int nho = 0;
    string res = "";
    for(int i = (int)a.length() - 1; i >= 0; i--)
    {
        int s = a[i] - '0' + b[i] - '0' + nho;
        if (s > 9)
        {
            s -= 10;
            nho = 1;
        } else nho = 0;
        res = (char)(s + '0') + res;
    }
    if (nho > 0) res = "1" + res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << add(a, b) << endl;
    }
}

// 999999999999999999
