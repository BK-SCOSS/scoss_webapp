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
#define Unique(a)       (a).resize(unique(all(a)) - (a).begin())
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

const int Nmax = 3e5 + 5;

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
 
void sieve(int maximum) {
    maximum = max(maximum, 2);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
 
    for (long long p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
 
            for (long long i = p * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}
 
// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
vector<pair<long long, int>> prime_factorize(long long n) {
    assert(1 <= n && n <= (long long) smallest_factor.size() * (long long) smallest_factor.size());
    vector<pair<long long, int>> result;
 
    if (n < (int) smallest_factor.size()) {
        while (n != 1) {
            long long p = smallest_factor[n];
            int exponent = 0;
 
            do {
                n /= p;
                exponent++;
            } while (n % p == 0);
 
            result.emplace_back(p, exponent);
        }
 
        return result;
    }
 
    for (long long p : primes) {
        if (p * p > n)
            break;
 
        if (n % p == 0) {
            result.emplace_back(p, 0);
 
            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }
 
    if (n > 1)
        result.emplace_back(n, 1);
 
    return result;
}
 
void solve(){
  long long n;
  cin >> n;
  // sieve(n + 5);
  // auto p = prime_factorize(n);
  // map<int, int> mp;
  // for(auto _p: p){
  //   mp[_p.st] += _p.nd;
  // }
  // p = prime_factorize(n + 1);
  // map<int, int> mp;
  // for(auto _p: p){
  //   mp[_p.st] += _p.nd;
  // }
  // p = prime_factorize(n + 2);
  // map<int, int> mp;
  // for(auto _p: p){
  //   mp[_p.st] += _p.nd;
  // }
  // vector<int> divisor;
  long long T = n * (n + 1) * (n + 2);
  ll T2 = T * T;
  long long res = 0;
  for(ll i = 1; i <= T; i++){
    if((T2 % i) == 0 && (T % i)){
      res++;
    }
  }
  cout << res << "\n";
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
  cin >> query;
  int start = 1000 * clock() / CLOCKS_PER_SEC;
  while(query--) solve();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC  - start << "ms\n";
}
