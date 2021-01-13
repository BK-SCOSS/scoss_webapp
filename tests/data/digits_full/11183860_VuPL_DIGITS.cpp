#include<bits/stdc++.h>

using namespace std;

int X[7];//0:H 1:U 2:S 3:T 4:I 5:O 6:C HUST SOICT 0123 25463
int mark[10];
int ans;

void solution(int N){
	long T = 1000*X[0] + 100*X[1] + 10*X[2] + X[3] + 10000*X[2] + 1000*X[5] + 100*X[4] + 10*X[6] + X[3];
	if(T == N){
		ans++;
	}
}

void TRY(int k, int N){
	for(int i = 0; i <= 9; i++){
		if(mark[i] == 0){
			X[k] = i;
			mark[i] = 1;
			if(k == 6){
				solution(N);
			}else{
				TRY(k+1, N);
			}
			mark[i] = 0;
		}
	}
}

void init(){
	for(int i = 0; i <= 9; i++){
		mark[i] = 0;
	}
}

void solve(int N){
	init();
	ans = 0;
	TRY(0, N);
	cout << ans << endl;
}

int main(){
	long n;
	cin >> n;
	long N[n];
	for(int i = 0; i < n; i++){
		cin >> N[i];
	}
	for(int i = 0; i < n; i++){
		solve(N[i]);
	}
}