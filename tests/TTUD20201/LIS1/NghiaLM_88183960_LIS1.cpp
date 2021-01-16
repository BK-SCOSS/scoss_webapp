#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+7;
int n;
int a[maxN];
int S[maxN];
int T;

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}
		S[1]=1;
		int res=S[1];
		for(int i=2; i<=n; i++){
			S[i]=1;
			for(int j=1; j<=i-1; j++){
				if(a[i]-a[j]==1){
					S[i]=max(S[i], S[j]+1);
				}
			}
			if(res<S[i]) res=S[i];
		}
		cout << res;
	}
	return 0;
	
}

