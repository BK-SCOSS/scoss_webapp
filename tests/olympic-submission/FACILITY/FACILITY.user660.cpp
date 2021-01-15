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

const int Nmax = 1e6 + 5;
 
template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    T tree_sum = 0;
    vector<T> tree;
 
    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }
 
    void init(int n) {
        tree_n = n;
        tree_sum = 0;
        tree.assign(tree_n + 1, 0);
    }
 
    // O(n) initialization of the Fenwick tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert((int) initial.size() == tree_n);
        tree_sum = 0;
 
        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];
            tree_sum += initial[i - 1];
 
            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }
 
    // index is in [0, tree_n).
    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);
        tree_sum += change;
 
        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] = max(tree[i], change);
    }
 
    // Returns the sum of the range [0, count).
    T query(int count) const {
        assert(count <= tree_n);
        T sum = 0;
 
        for (int i = count; i > 0; i -= i & -i)
            sum = max(sum, tree[i]);
 
        return sum;
    }
 
    // Returns the sum of the range [start, tree_n).
    T query_suffix(int start) const {
        return tree_sum - query(start);
    }
 
    // Returns the sum of the range [a, b).
    T query(int a, int b) const {
        return query(b) - query(a);
    }
 
    // Returns the element at index a in O(1) amortized across every index. Equivalent to query(a, a + 1).
    T get(int a) const {
        assert(0 <= a && a < tree_n);
        int above = a + 1;
        T sum = tree[above];
        above -= above & -above;
 
        while (a != above) {
            sum -= tree[a];
            a -= a & -a;
        }
 
        return sum;
    }
 
    // Returns the largest i in [0, tree_n] such that query(i) <= sum. Returns -1 if no such i exists (sum < 0).
    // Can be used as an ordered set on indices in [0, tree_n) by using the tree as a 0/1 array:
    // update(index, +1) is equivalent to insert(index); be careful not to double insert.
    // update(index, -1) is equivalent to erase(index); again be careful not to double erase.
    // get(index) provides whether index is present or not.
    // query(index) provides the count of elements < index.
    // find_last_prefix(k) finds the k-th smallest element (0-indexed).
    int find_last_prefix(T sum) const {
        if (sum < 0)
            return -1;
 
        int prefix = 0;
 
        for (int k = 31 - __builtin_clz(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }
 
        return prefix;
    }
};

struct goods{
  long long s;
  long long d;
  long long r;
} a[Nmax];
// 4 5 6 7
void solve(){
  int n, k;
  cin >> n >> k;
  fenwick_tree<long long> fenw(n + 10);
  for(int i = 0; i < n; i++){
    ll s, d, r;
    cin >> s >> d >> r;
    a[i] = {s, d, r};
  }
  sort(a, a + n, [](goods x, goods y){
    return x.s < y.s;
  });

  vector<ll> b(n);
  for(int i = 0; i < n; i++){
    b[i] = a[i].s;
  }

  long long res = 0;

  for(int i = 0; i < n; i++){
    ll value = a[i].r;
    int id = upb(all(b), a[i].s) - b.begin() - 1;
    if(id >= 0){
      value += fenw.query(id + 1);
      res = max(res, value);
    }
    res = max(res, value);
    id = lwb(all(b), a[i].s + a[i].d + k) - b.begin();
    fenw.update(id, value);
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
  // cin >> query;
  int start = 1000 * clock() / CLOCKS_PER_SEC;
  while(query--) solve();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC  - start << "ms\n";
}
