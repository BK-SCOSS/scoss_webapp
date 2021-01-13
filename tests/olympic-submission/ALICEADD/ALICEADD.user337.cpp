#include <bits/stdc++.h>

using namespace std;

int main()
{
  unsigned long long a, b;
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    cin >> a >> b;
    unsigned long long a0 = a % 10;
    unsigned long long a1 = (a - a0 ) / 10;
    unsigned long long b0 = b % 10;
    unsigned long long b1 = (b - b0 ) /10;
    unsigned long long c0 = ( a0 + b0 ) % 10;
    unsigned long long c1 = ( a0 + b0 - c0 ) / 10;
    c1 = a1 + b1 + c1 ;
    if(c1 > 0) cout << c1;
    cout << c0 << endl;
  }
  return 0;
}
