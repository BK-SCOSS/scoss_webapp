#include <bits/stdc++.h>

using namespace std;

struct data {
  int s, e, d, r;
  bool operator < (const data&other) const {
    if (e < other.e) return true;
    if (e > other.e) return false;
    return s < other.s;
  }
};
const int N = 1e6+1;
int n, K;
data a[N];
long long T[4*N];
long long f[N];

/// IT
void modify(int node, int l, int r, int ql, int qr, long long val) {
  if (l > qr || ql > r) return;
  if (ql <= l && r <= qr) {
    T[node] = max(T[node], val);
    return;
  }
  int mid = (l + r) >> 1;
  modify(node + node, l, mid, ql, qr, val);
  modify(node + node + 1, mid + 1, r, ql, qr, val);
  T[node] = max(T[node+node], T[node+node+1]);
}

long long get(int node, int l, int r, int ql, int qr) {
  if (l > qr || ql > r) return 0;
  if (ql <= l && r <= qr) return T[node];
  int mid = (l + r) >> 1;
  long long x = get(node+node, l, mid, ql, qr);
  long long y = get(node+node+1, mid+1, r, ql, qr);
  return max(x, y);
}

void compress() {
  set<int> s;
  set<int>::iterator it;
  map<int, int> foo;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    s.insert(a[i].s);
    s.insert(a[i].e);
  }
  for (it = s.begin(); it != s.end(); it++) {
    int value = *it;
    cur++;
    foo[value] = cur;
  }
  for (int i = 1; i <= n; i++) {
    a[i].s = foo[a[i].s];
    a[i].e = foo[a[i].e];
  }
}

void work() {
  cin >> n >> K;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].s >> a[i].d >> a[i].r;
    a[i].e = a[i].s + a[i].d + K - 1;
  }
  compress();
  sort(a + 1, a + n + 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = a[i].r;
    int lo = 1, hi = i - 1, ret = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (a[mid].e < a[i].s) {
        ret = mid;
        lo = mid + 1;
      }
      else hi = mid - 1;
    }
    if (ret != -1) f[i] = max(f[i], get(1, 1, n, 1, ret) + a[i].r);
    modify(1, 1, n, i, i, f[i]);
    ans = max(ans, f[i]);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  ///freopen ("facility.inp", "r", stdin);
  ///freopen ("facility.out", "w", stdout);

  work();

  return 0;
}
