/*********THACH THAO*********/

#include <bits/stdc++.h>
#define maxC 1000000007
#define maxn
#define Task "ALICEADD"
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int T;
string a, b;

void in()
{
    cin >> T;
}

string sum(string p, string q)
{
    int re = 0, xsz = 0, ysz = 0, cur;
    int x[30], y[30];
    string res = "";
    for (int i = p.length()-1; i >= 0; --i) {
        x[++xsz] = p[i] - '0';
    }
    for (int i = q.length()-1; i >= 0; --i) {
        y[++ysz] = q[i] - '0';
    }
    for (int i = 1; i <= max(xsz, ysz); ++i) {
        cur = re + x[i] + y[i];
        if (cur <= 9) {
            char ch = cur + '0';
            res = ch + res;
            re = 0;
        } else {
            re = cur / 10;
            cur %= 10;
            char ch = cur + '0';
            res = ch + res;
        }
    }
    while (re) {
        char ch = re % 10 + '0';
        res = ch + res;
        re /= 10;
    }
    return res;
}

void solve()
{
    while (T--) {
        cin >> a >> b;
        cout << sum(a, b) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
	in();
    solve();
    return 0;
}
