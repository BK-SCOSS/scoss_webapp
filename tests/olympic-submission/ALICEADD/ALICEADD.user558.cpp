#include <bits/stdc++.h>

using namespace std;

int t;

string a, b;

int charToNum(char x) { return x - 48; }
char numToChar(int x) { return x + 48; }

void normalize(string &x, string &y) {
    int lx = x.size();
    int ly = y.size();
    if (lx < ly) x.insert(0, ly - lx, '0');
    else y.insert(0, lx - ly, '0');
}

string sum(string x, string y) {
    string s = "";
    normalize(x,y);
    int l = x.size(), temp = 0;
    for (int i = l - 1; i >= 0; --i) {
        temp += charToNum(x[i]) + charToNum(y[i]);
        s = numToChar(temp % 10) + s;
        temp /= 10;
    }
    if (temp > 0) s = numToChar(temp) + s;
    return s;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t --> 0) {
        cin >> a >> b;
        cout << sum(a, b) << "\n";
    }
}
