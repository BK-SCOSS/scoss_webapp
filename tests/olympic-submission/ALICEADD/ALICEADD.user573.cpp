#include <iostream>

using namespace std;

string add(string a, string b) {
    string s = "";
    int l1 = a.length(), l2 = b.length();
    while (l1 < l2) {
        a = "0" + a;
        l1++;
    }
    while (l1 > l2) {
        b = "0" + b;
        l2++;
    }
    int r = 0;
    for (int i = l1 - 1; i >= 0; i--) {
        int d = a[i] - '0' + b[i] - '0' + r;
        string temp = to_string(d % 10);
        if (d > 9) {
            r = 1;
        } else {
            r = 0;
        }
        s = temp + s;
        if (i == 0 && r == 1) {
            s = "1" + s;
        }
    }
    return s;
}

void solve() {
    int n = 0;
    string a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << add(a, b) << "\n";
    }
}

int main() {
    solve();
    return 0;
}