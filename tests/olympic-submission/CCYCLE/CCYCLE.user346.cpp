#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
const int N = 3*1e4+10;
vector<int>adj[N];
void adds(int a, int b) {
  adj[a].push_back(b);
  adj[b].push_back(a);
}
int f[N][1001];
int n,L,s,t;
void work() {
  cin >> n >> L >> s >> t;
  n*=3;
  for(int i = 1; i <= n; i++) {
    if (i%3==1) {
      adds(i,i+1);
      adds(i,i+2);
      if (i!=1) adds(i,i-1);
    }
  }
  adds(1,n);
  f[s][0] = 1;
  for (int i = 0; i <= L; i++) {
    for (int u = 1; u <= n; u++) {
      for (int v : adj[u]) {
        add(f[v][i + 1], f[u][i]);
      }
    }
  }
  cout << f[t][L] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  work();

  return 0;
}
