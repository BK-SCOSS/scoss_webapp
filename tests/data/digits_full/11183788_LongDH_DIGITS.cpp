#include <stdio.h>
int X[7];
int appeared[10];
int ans;
int soluong;
int t[30];
int N;
void solution(){
int T = X[0]*1000 + X[1]*100 + X[2]*10+2*X[3] + X[2]*10000 +X[4]*1000 + X[5]*100+X[6]*10;

if(T == N){
ans++;

}
}
void init(){
for(int v = 1; v <= 9; v++) appeared[v] = 0;
}

void TRY(int k){
for(int v = 1; v <= 9; v++){
if(appeared[v] == 0){
X[k] = v;
appeared[v] = 1;
if(k == 6){
solution();
}else{
TRY(k+1);
}
appeared[v] = 0;
}
}
}

void solve(){
	scanf("%d",&soluong);
	for(int i=1;i<=soluong;i++ ) scanf("%d",&t[i]);
    

        	
	
	for( int i=1;i<=soluong;i++){
	    N =t[i];
		ans = 0;
		init();
        TRY(0);
        printf("%d",ans);
        printf("\n");
	
}

}
int main(){
solve();
}
