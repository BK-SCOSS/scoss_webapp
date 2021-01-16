#include<bits/stdc++.h>
using namespace std;

int T;
int const MAX = 1e5+10;
int n;
unsigned long long a[MAX];
int dp[MAX];

void input(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >>a[i];
		dp[i] = 1;
	}
}

void init_dp(){
	for(int i=1; i<=n; i++){
		dp[i] = 0;
	}
	dp[1] = 1;
}


int main(){
	cin >> T;
	while(T!=0){
		T= T-1;
		int res = 0;
		input();
//		init_dp();
		for(int i=2; i<=n; i++){
			dp[i] = 1;
			for(int j=1; j<i; j++){
				if(a[j] == a[i] -1 && dp[i] < dp[j]+1){
					dp[i] = dp[j]+1;
				}
			}
			if(dp[i] > res){
				res = dp[i];
			}
		}
		cout << res;
	}
	
	return 0;
}



