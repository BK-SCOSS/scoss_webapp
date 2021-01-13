#include<bits/stdc++.h>
using namespace std;
#define MAXN 21
int main () {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int a[MAXN], b[MAXN];
        for (int i = 0; i  < MAXN; i++) {
            a[i] = 0;
            b[i] = 0;
        }
        int l1 = s.length();
        for (int i = 1; i <= l1; i++) {
            a[MAXN-i] = s[l1-i]-'0';
        }
        int l2 = t.length();
        for (int i = 1; i <= l2; i++) {
            b[MAXN-i] = t[l2-i]-'0';
        }
        
        int c[MAXN];
        int carry = 0;
        for (int i = 0; i < MAXN; i++) {
            c[i] = 0;
        }
        for (int i = MAXN-1; i >= 0; i--) {
            int sum = a[i] + b[i] + carry;
            c[i] = sum % 10;
            carry = sum / 10;
        }
        int i = 0;
        while (i < MAXN && c[i] == 0) {
            i++;
        }
        if (i == MAXN) {
            cout << 0 << '\n';
        } else {
            for (int j = i; j < MAXN; j++) {
                cout << c[j];
            }
            cout << '\n';
        }
    }
    return 0;
}