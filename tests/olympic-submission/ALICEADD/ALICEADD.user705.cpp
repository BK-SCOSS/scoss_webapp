#include <iostream>
#include <string>
using namespace std;
void Add(string a, string b)
{
    while (a.length() < b.length()) a = '0' + a;
    while (b.length() < a.length()) b = '0' + b;
    int n = a.length();
    string c = "";
    int carry = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int d = a[i] - '0' + b[i] - '0' + carry;

        c = (char)(d % 10 + '0') + c;
        carry = d / 10;
    }
    if (carry == 1)
        c = '1' + c;
    cout << c;
}
int main()
{
    string a, b;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        // cout << a + b << '\n';
        Add(a, b);
    }
}
