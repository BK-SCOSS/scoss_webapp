#include <stdio.h>

int x[7];
int appeared[10];
int ans, N;
void solution(){
  int T = x[0]*1000 + x[1]*100 + x[2]*10 + x[3] +
          x[2]*10000 + x[4]*1000 + x[5]*100 + x[6]*10 + x[3];
  if(T == N && x[0]*x[2] != 0) ans++;
}

void TRY(int k){
  for(int v = 0; v <= 9; v++){
    if(appeared[v] == 0){
      x[k] = v;
      appeared[v] = 1;
      if(k == 6) solution();
      else TRY(k+1);
      appeared[v] = 0;
    }
  }
}

void solve(){
  int T;
  scanf("%d",&T);
  int t = T;
  int res[T];
  while(T){
  scanf("%d",&N);
  for(int v = 0; v <= 9; v++) appeared[v] = 0;
  ans = 0;
  TRY(0);
  res[T] = ans;
  T--;
  }

  for (int i = t; i >= 1; i--) printf("%d\n",res[i]);
}

int main(){
  solve();
}
