#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

struct task{
  int s, f, r;

  task(){};

  task(int _s, int _f, int _r) {
     s = _s;
     f = _f;
     r = _r;
  }

}a[N];

bool cmp(task p, task q)
{
  if(p.f != q.f) return p.f < q.f;
  return p.s < q.s;
}

int n, k;
int val[2*N];
long long d[N];
vector<int> vs, vf;

int main()
{
  ios_base::sync_with_stdio(false);
  //freopen("inp.txt", "r", stdin);
  int x, y, z;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> x >> y >> z;
    a[i] = task(x, x + y + k - 1, z);
    vs.push_back(x);
    vf.push_back(x + y + k - 1);
  }

  sort(a + 1, a + n + 1, cmp);
  sort(vs.begin(), vs.end());
  sort(vf.begin(), vf.end());

  for(int i = 1; i <= n; i++) {
    int poss = lower_bound(vf.begin(), vf.end(), a[i].s) - vf.begin();
    d[i] = max(d[i - 1], d[poss] + 1ll * a[i].r);
  }
  cout << *max_element(d + 1, d + n + 1);
  return 0;
}
