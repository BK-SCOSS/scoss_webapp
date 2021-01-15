#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1E6+3;

int max_prime_divisible[MAXN];

long long count_divisible(int x);
long long count_divisible_square(int x);

long long calculate(int n){
  int div_2_cnt = 0;
  long long ans = 1LL, ans_square=1LL;
  for(int j=0; j< 3; ++j){
    int x = n+j;
    while(!(x&1)){
      ++div_2_cnt;
      x >>=1;
    }
    ans *= count_divisible(x);
    ans_square *= count_divisible_square(x);
  }
  return ((ans_square*1LL*(2*div_2_cnt+1)+1) >> 1) - ans*1LL*(div_2_cnt+1);
}


signed main(){
#ifdef LOCAL_DEBUG
  freopen("test-inp.txt", "r", stdin);
  freopen("test-out.txt", "w", stdout);
#endif
  for(int i=2; i< MAXN; ++i){
    if(!max_prime_divisible[i]){
      max_prime_divisible[i] = i;
      for(int j=i+i; j < MAXN; j+=i) max_prime_divisible[j] = i;
    }
  }
  int Q; cin >> Q;
  while(Q--){
    int n; cin >> n;
    cout << calculate(n) << "\n";
  }
}

long long count_divisible(int x){
  long long ans = 1LL;
  while(x > 1){
    int mx_pr = max_prime_divisible[x];
    int cnt = 0;
    while(max_prime_divisible[x] == mx_pr){
      ++cnt;
      x /= max_prime_divisible[x];
    }
    ans *= 1LL*(cnt+1LL);
  }
  return ans;
}

long long count_divisible_square(int x){
  long long ans = 1LL;
  while(x > 1){
    int mx_pr = max_prime_divisible[x];
    int cnt = 0;
    while(max_prime_divisible[x] == mx_pr){
      cnt+=2;
      x /= max_prime_divisible[x];
    }
    ans *= 1LL*(cnt+1LL);
  }
  return ans;
}