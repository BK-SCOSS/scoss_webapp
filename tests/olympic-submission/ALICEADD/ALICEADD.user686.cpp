#include <iostream>
#include <math.h>
#include <string>
using namespace std;
string AddString(string s1, string s2) {
    string res = "";
    if (s1.length() > s2.length())
        swap(s1, s2);
    while (s1.length() != s2.length())
        s1 = '0' + s1;
    int remem = 0;
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        int temp = int(s1[i] - 48) + int(s2[i] - 48) + remem;
        res = char(temp % 10 +48) + res;
        remem = temp / 10;
    }
    if (remem != 0)
        res = char(remem % 10 + 48) + res;
    return res;
}
int main() {
    int t;
    string a, b;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> a >> b;
        cout << AddString(a, b);
    }
}
