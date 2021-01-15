#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1E6+2;

struct Customer{
  int start;
  int end;
  int rent;
};

int n, K;
Customer c[MAXN];
long long f[MAXN];


signed main(){
#ifdef LOCAL_DEBUG
  freopen("test-inp.txt", "r", stdin);
  freopen("test-out.txt", "w", stdout);
#endif
  cin >> n >> K;
  for(int i=1; i<=n; ++i){
    cin >> c[i].start >> c[i].end >> c[i].rent;
    c[i].end += c[i].start-1;
  }
  sort(c+1, c+n+1, [&](Customer c1, Customer c2){
    if(c1.end == c2.end){
      if(c1.start == c2.start) return c1.rent < c2.rent;
      return c1.start < c2.start;
    }
    return c1.end < c2.end;
  });
  f[0] = 0;
  c[0] = {0, 0, 0};
  for(int i=1; i<= n; ++i){
    int l=0, r = i-1, index = -1;
    while(l<=r){
      int mid = (l+r)>>1;
      if(c[mid].end < c[i].start - K){
        index = mid;
        l=mid+1;
      }
      else r = mid-1;
    }
    f[i] = max(f[i-1], f[index] + 1LL*c[i].rent);
  }
  cout << f[n];
  return 0;
}