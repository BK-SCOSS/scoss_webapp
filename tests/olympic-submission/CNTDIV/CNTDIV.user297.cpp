#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
  int Q;
  cin >> Q;
  int r[Q];
  for(int i=0;i<Q;i++){
    int N;
    cin >> N;
    int T;
    T = N*(N+1)*(N+2);
    int Y = T*T;
    int d = 0;
    for(int i=1;i<=Y;i++){
      if(Y%i==0&&i<T&&!(T%i==0)){
        d++;
      }
    }
    r[i] = d;
  }
  for(int i=0;i<Q;i++){
    cout<<r[i]<<endl;
  }
  return 0;
}
