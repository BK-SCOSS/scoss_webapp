#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int Max = 100001;

int n;


void solve(){
	cin >> n;
	int ans = 0;
	int tmp = n*(n+1)*(n+2);
	for(int i=2; i<tmp; ++i){
		if((tmp*tmp)%i==0 && tmp%i!=0)
		    ans++;
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
