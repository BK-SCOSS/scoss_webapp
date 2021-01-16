#include <bits/stdc++.h>
using namespace std;

//void solve(){
//S[0] = 1;
//rs = S[0];
//for(int i = 1; i < n; i++){
//S[i] = 1;
//for(int j = i-1; j >= 0; j--){
//if(a[i] > a[j]){
//if(S[j] + 1 > S[i])
//S[i] = S[j] + 1;
//}
//}
//rs = S[i] > rs ? S[i] : rs;
//}
//printf("rs = %d\n",rs);
//}

int main(){
	int t,n;
	cin >> t;
	while(t>0){
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++) cin >> a[i];
		
		int S[n],rs;
		S[0] = 1;
	rs = S[0];
	for(int i = 1; i < n; i++){
	S[i] = 1;
	for(int j = i-1; j >= 0; j--){
		if(a[i]  == a[j]+1){
			if(S[j] + 1 > S[i])
				S[i] = S[j] + 1;
		}	
	}
	rs = S[i] > rs ? S[i] : rs;
}
	cout << rs;	
	t--;
	}
}
