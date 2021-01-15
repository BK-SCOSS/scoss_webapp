#include <bits/stdc++.h>
using namespace std;
 
#define st              first
#define nd              second
#define pb              push_back
#define lwb             lower_bound
#define upb             upper_bound
#define Size(a)         int((a).size())
#define reset(s, n)     memset(s, n, sizeof(s))
#define bit(n, i)       (((n) >> (i)) & 1)
#define cntbit(n)       __builtin_popcountll(n)
#define all(a)          (a).begin(), (a).end()
#define unique(a)       (a).resize(unique(all(a)) - (a).begin())
#define Max(a, b, c)    max(max((ll)(a), (ll)(b)), (ll)(c))
#define Min(a, b, c)    min(min((ll)(a), (ll)(b)), (ll)(c))
 
typedef long double ld;
typedef long long ll;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-7;
inline ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline int inv(int a, ll p = MOD) {return fpow(a, p - 2, p);}
inline ll lcm(ll a, ll b) {return a / __gcd(a, b) * b;}
inline void onbit(ll &a, int i){a |= 1LL << i;}
inline void offbit(ll &a, int i){onbit(a, i), a -= (1LL << i);}
 
const int N = 3e5 + 5;

struct matrix{
  int n;
  long long values[151][151];
 
  matrix (int _n){
    n = _n;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
        values[i][j] = 0;
    }
  }
 
  matrix operator * (matrix &other){
    matrix res(n);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        res.values[i][j] = 0;
        for(int k = 0; k < n; k++){
          res.values[i][j] =  (res.values[i][j] + values[i][k] * other.values[k][j]) % MOD;
        }
      }
    }
    return res;
  }
 
  matrix pow_maxtrix(ll p){
    matrix temp = *this;
    matrix res = temp;
    p--;
    while(p > 0){
      if(p & 1){
        res = res * temp;
      }
      if(p > 1) temp = temp * temp;
      p >>= 1;
    }
    return res;
  }
 
};
 
void solve(){
  int n, k;
  int s, t;
  cin >> n >> k;
  cin >> s >> t;

  if(n > 50){
    n *= 3;
    vector<long long> a(n, 0);
    s %= n;
    t %= n;
    a[s] = 1;
    for(int l = 1; l <= k; l++){
      vector<long long> b(n, 0);
      for(int i = 0; i < n; i++){
        if((i % 3) == 1){
          b[i] = (a[i - 1] + a[i + 1] + a[(i + 2) % n]) % MOD;
        }
        if((i % 3) == 2){
          b[i] = a[i - 1];
        }
        if((i % 3) == 0){
          b[i] = (a[(i - 2 + n) % n] + a[i + 1]) % MOD;
        }
      }
      a = b;
    }
    cout << a[t] << "\n";
    return;
  }

  matrix mtrix(n * 3 + 1);
  for(int i = 0; i < n; i++){
    if(3 * i > 0) mtrix.values[3 * i + 1][3 * i] = 1;
    mtrix.values[3 * i + 1][3 * i + 2] = 1;
    mtrix.values[3 * i + 1][3 * i + 3] = 1;
    if(3 * i > 0) mtrix.values[3 * i][3 * i + 1] = 1;
    mtrix.values[3 * i + 2][3 * i + 1] = 1;
    mtrix.values[3 * i + 3][3 * i + 1] = 1;
  }
  mtrix.values[1][3 * n] = mtrix.values[3 * n][1] = 1;
  mtrix = mtrix.pow_maxtrix(k);
  cout << mtrix.values[s][t] << "\n";
}
 
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  cout << fixed << setprecision(10);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int query = 1;
  // cin >> query;
  int start = 1000 * clock() / CLOCKS_PER_SEC;
  while(query--) solve();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC  - start << "ms\n";
}