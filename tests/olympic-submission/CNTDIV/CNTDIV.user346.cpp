#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;
int n;
int pre[N];
long long ans;
void sieve() {
  for (int i = 1; i < N; i++) {
    pre[i] = i;
  }
  for (int i = 2; i * i < N; i++) {
    if (pre[i] == i) {
      for (int j = i * i; j < N; j += i) {
        pre[j] = i;
      }
    }
  }
}

long long U;
int times[N];
int fun[N];
vector<int> a;
void pt(int n) {
  while (n != 1) {
    a.push_back(pre[n]);
    times[pre[n]]++;
    n /= pre[n];
  }
}
void reset(int n) {
  while (n != 1) {
    times[pre[n]] = 0;
    n /= pre[n];
  }
}
long long Pow(int x, int y) {
  if (y == 0) return 1;
  long long z = Pow(x, y / 2);
  z = z * z;
  if (y % 2) return z * x;
  else return z;
}
void Try(int i) {
  for (int j = 0; j <= 2 * times[a[i]]; j++) {
    bool bigger = false;
    fun[i] = j;
    if (i == a.size() - 1) {
      /*for (int z = 0; z < a.size(); z++) {
        cout << a[z] << " " << fun[z] << "\n";
      }
      cout << "het\n";*/
      long long uoc = 1;
      long long T = 1LL * n * (n + 1) * (n + 2);
      for (int z = 0; z < a.size(); z++) {
        if ((long double)uoc >= (long double)T / (long double)Pow(a[z], fun[z])) {
          bigger = true;
          break;
        }
        uoc *= Pow(a[z], fun[z]);
        ///if (uoc > T) break;
      }
      if (T % uoc != 0 && !bigger) ans++;
    }
    else Try(i + 1);
  }
}
void work() {
  cin >> n;
  for (int i = 0; i <= 2; i++) pt(n + i);
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  ans = 0;
  Try(0);
  cout << ans << "\n";
  for (int i = 0; i <= 2; i++) reset(n + i);
  a.clear();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  ///freopen ("cntdiv.inp", "r", stdin);
  ///freopen ("cntdiv.out", "w", stdout);

  sieve();
  int Q;
  cin >> Q;
  while (Q--) {
    work();
  }

  return 0;
}
