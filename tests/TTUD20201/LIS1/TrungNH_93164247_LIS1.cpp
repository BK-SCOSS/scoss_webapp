#include<bits/stdc++.h>
using namespace std;
int n,a[100001],mem[100001];
int dp(int i){
	if(i==1){
		return 1;
	}
	if(mem[i]!=0) return mem[i];
	mem[i]=1;
	for(int j=1;j<i;j++){
		if(a[i]-1==a[j]){
			mem[i] = max(mem[i],1+dp(j));
		}
	}
	return mem[i];
}
main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			dp(i);
		}
		cout<<*max_element(mem+1,mem+n+1)<<endl;
	}
}
