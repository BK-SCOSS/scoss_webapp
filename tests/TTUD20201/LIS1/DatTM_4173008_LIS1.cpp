#include<bits/stdc++.h>
using namespace std;

int T,n;
long a[100005],b[100005],ans;


int listt(int cur){
	for(int i=cur;i <n;i++){
		if(a[cur]<a[i]) {
			b[cur]++;
		}
	}
	if (ans<b[cur]) ans=b[cur];
}

int main(){
	cin >> T;
	for(int k=1;k<=T;k++){
		cin >> n ;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}

		for(int i=1;i<=n;i++){
			listt(i);
		}
		cout << ans <<endl;
	}
	
  return 0;
}
