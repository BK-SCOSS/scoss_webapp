#include <stdio.h>
int X[7]; 
int appeared[10];
int ans, N;
void soluntion(){
	int T = X[0]*100 + X[1]*10 - X[3]*100 - 62 + X[4]*1000 + X[5]*100 + X[6]* 10 + X[2];
	if(T == N){
		ans++;
	}
}
void init(){
	for(int v = 0; v <= 9; v++) appeared[v]=0;
	}
void TRY(int k){
		for(int v = 0; v <=9; v++){
			if(appeared[v]==0){
				X[k] = v;
				appeared[v] = 1;
				if(k == 6){
				   soluntion();
				}
				else{
				TRY(k+1);
				}
				appeared[v]= 0;
				}
			}
		}
	void solve(){
		scanf("%d",&N);
		init();
		ans = 0;
		TRY(0);
		printf("%d",ans);
	}
int main(){
	solve();
}

