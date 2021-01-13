#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  long long N;
  int Q;
  cin >> Q;
  int x[Q];
  for(int i=1;i<=Q;i++){
   x[i] = N;
   cin >> N;
   unsigned long long T = N*(N+1)*(N+2);
   unsigned long long B = T*T;
   int cnt1 = 0;
   for(int j=2;j<=T; j++){
    if(B%j==0 && T%j!=0){
        cnt1++;
    }
   }
    cout << cnt1 << endl;
  }
  return 0;
}
