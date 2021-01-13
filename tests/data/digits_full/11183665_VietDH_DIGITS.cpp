#include<bits/stdc++.h>

using namespace std;

int T, N;

int x[8];
int mark[10];
int ans = 0;

void solution(){
	if(x[1] != 0 and x[3] != 0){
		int a = x[1]*1000 + x[2]*100 + x[3]*10 + x[4];
		int b = x[3]*10000 + x[5]*1000 + x[6]*100 + x[7]*10 + x[4];
		if(a + b == N) ans++;
	}
	
}

void TRY(int k){
	for(int i=0; i<=9; i++){
		if( mark[i] == 0) {
			x[k] = i;
			mark[i] = 1;
			if(k == 7)	solution();
			else TRY(k+1);
			mark[i] = 0;
		}
	}	
}

int main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>N;
		ans = 0;
		TRY(1);
		cout<<ans<<endl;
	}
}
