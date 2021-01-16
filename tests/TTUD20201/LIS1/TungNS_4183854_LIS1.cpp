#include<iostream>
using namespace std;
int T, n;
int a[1000];
int s[10000];
int res;
int solve(){
	s[1] = 1;
	res = s[1];
	for(int i = 2; i <= n;i++){
		s[i] = 1;
	for(int j = 1; j <= i-1; j++){
		if (a[j] < a[i] ){
			if(s[i] , s[i] + 1){
				s[i] = s[j]+1;
			}
		}
	}
	if(s[i] > res) res = s[i];
	}
	return res;
}
int main(){
	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> n;
		for (int j = 0; j < n; j++){
			cin >> a[j];
		}
		solve();
	}
	
	cout << res-1;
	return 0;
}
