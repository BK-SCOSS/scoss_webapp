#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const int M = 100005;

int n, np;
int d[N];
vector <int> prime;
long long nT2, nT;
map <int, int> p;

void siege()
{
  for(int i = 2; i < N; i++) {
    if(!d[i]){
      prime.push_back(i);
      d[i] = i;
      for(int j = i*2; j < N; j += i) d[j] = i;
    }
  }
  np = prime.size();
}

void process(int m, map<int, int> &mp)
{
  while(m > 1) {
    mp[d[m]] ++;
    m /= d[m];
  }
}

int main()
{
  int T;
  cin >> T;
  siege();
  for(int i = 1; i <= T; i++) {
    cin >> n;
    p.clear();
    process(n, p);
    process(n+1, p);
    process(n+2, p);
    nT = 1;
    nT2 = 1;
    for(auto u: p) {
      nT *= (u.second + 1);
      nT2 *= (2 * u.second + 1);
    }
    cout << nT2 / 2 - nT + 1<< endl;
  }
  return 0;
}
