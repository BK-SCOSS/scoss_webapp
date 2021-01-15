#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10; 

struct T {
    int start;
    int finish;
    int money;
    T(){}
    T(int _start, int _duration, int _money): start(_start), finish(_start + _duration), money(_money) {}
}a[MAXN];
 
bool cmp(T foo, T bar) {
    return foo.start < bar.start;
}
 
int n, k;
priority_queue<pair<int, long long>> q;
 
int main() {
	//freopen("1.inp", "r", stdin);
    cin >> n >> k;
 
    for (int i = 1; i <= n; ++ i) {
        int start, duration, money;
        cin >> start >> duration >> money;
        a[i] = T(start, duration, money);
    }
 
    sort(a + 1, a + n + 1, cmp);
 
    long long best = 0;
    long long ans = 0;
 
    for (int i = 1; i <= n; ++ i) {
        while (!q.empty() && -q.top().first <= a[i].start) {
            best = max(best, q.top().second);
            q.pop();
        }
        long long benefit = best + 1ll * a[i].money;
        ans = max(ans, benefit);
        q.push(make_pair(-(a[i].finish + k), benefit));
    }
 
    cout << ans << '\n';
 
    return 0;
}