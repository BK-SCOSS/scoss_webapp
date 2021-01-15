#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef long long LL;
typedef tree<LL, null_type, less<LL>,
          rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int main(){
//  ios::sync_with_stdio(false);
//  cin.tie(0);
  LL n, K; cin >> n >> K;
  struct Bill{
    LL start;
    LL day;
    LL val;
    Bill(LL s, LL d, LL v){
      start = s; day = d; val = v;
    }
  };
//  vector<Bill> v;
//  for (int i = 0; i < n; i++){
//    LL s, d, r; cin >> s >> d >> r;
//    v.push_back(Bill(s, d, r));
//  }
  // compress
  map<LL, vector<Bill>> sts;
  for (int i = 0; i < n; i++){
    LL s, d, r; cin >> s >> d >> r;
    sts[s + d - 1 + K].push_back(Bill(s, d, r));
  }
  vector<LL> dp(100000);
  for (int i = 1; i < 100000; i++){
    dp[i] = dp[i - 1];
    for (Bill b : sts[i]){
      dp[i] = max(dp[i], dp[b.start - 1] + b.val);
    }
  }
  cout << dp[99999] << endl;
}
