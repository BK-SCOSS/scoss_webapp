#include <bits/stdc++.h>

#define MAX_INT 2e9
#define maxl 1000000
#define ln length()
#define ff(i,a,b) for(int i = a; i <= b; i++)
#define fb(i,a,b) for(int i = a; i >= b; i--)
typedef long long ll;
using namespace std;

inline void equalize(string &a, string &b) { // add '0' to the left of a/b to make equal length
    int diff = a.ln - b.ln; 
    diff = abs(diff);
    string z(diff, '0');
    if (a.ln < b.ln) a = z + a;
    else b = z + b;
}

string cuthead(string s) { // cut unnecessary '0's at the left of a number
    int count = 0;
    while (s[count] == '0' && count < s.ln - 1) count++;
    return s.substr(count, s.ln - count);
}

string sum(string a, string b) { // sum a + b
    int rem = 0; 
    string s = "";
    equalize(a, b);
    fb(i,a.ln-1,0) {
        int temp = a[i] + b[i] + rem - '0' * 2;
        rem = temp / 10;
        temp %= 10;
        s = (char)(temp + '0') + s;
    }
    if (rem) s = '1' + s;
    return cuthead(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string a, b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << sum(a,b) << endl;
    }
}
