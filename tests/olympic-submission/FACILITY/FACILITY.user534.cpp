/**
    *Makacha
**/
#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read (T &x) {bool b = 0; char c; while (!isdigit (c = getchar()) && c != '-');
if (c == '-') c = getchar(), b = 1; x = c - 48; while (isdigit(c = getchar())) x = (x<<3) + (x<<1) + c - 48; if (b)x=-x;}
template <typename T> inline void wrip(T x) {if (x > 9) wrip(x / 10); putchar(x%10 + 48); }

template <typename T> inline void write(T x) {if (x < 0) putchar('-'), x = -x; wrip(x); putchar(' ');}
template <typename T> inline void writeln(T x) {if (x < 0) putchar('-'), x = -x; wrip(x); putchar('\n');}
inline char readch() {char c; do c = getchar(); while (c == '\n' || c == ' '); return c;}
inline void reads(string &s) {char c; while((c=getchar())==' '||c =='\n'); s=c; while((c=getchar())!=' '&&c!='\n') s+=c;}
inline void getlines(string &s) {char c; while((c=getchar())=='\n'); s=c; while((c=getchar())!='\n') s+=c;}
typedef const int csint;

#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;

const ld pi = acos(-1);
const int inf = 1e9 + 11,
mod = 1e9 + 7,
N = 1e6 + 11;

struct stc{
    ll start, len, finish, cost;
};
stc a[N];
bool cmp(stc a, stc b) {
    return a.finish < b.finish;
}
int n, K;
ll f[N];
int main() {
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    read(n);
    read(K);
    for (int i = 1; i <= n; i++) {
        read(a[i].start);
        read(a[i].len);
        read(a[i].cost);
        a[i].finish = a[i].start + a[i].len + K;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (a[mid].finish <= a[i].start)
                l = mid + 1;
            else
                r = mid - 1;
        }
        f[i] = max(f[i - 1], f[r] + a[i].cost);
    }
    cout << f[n];
}
