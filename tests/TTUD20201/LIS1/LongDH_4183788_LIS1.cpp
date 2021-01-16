#include<bits/stdc++.h>
using namespace std;
int T;	int n; int a[100001];
 int save[1000001]; int res;
void input(){
	cin>>n;	for(int i=0;i<n;i++) cin>>a[i];
}
void init(){
	for(int i=0;i<n;i++) save[i]=-1;
}	
void LIS(int k){
	if(k==0) save[k]=1;
	for(int i=0;i<k;i++){
		if(a[k]==a[i]+1){
			save[k] =max(save[k],save[i]+1);
		}
	}
}
int main(){
	cin>>T;
	while(T--){
		input();
		init();
		res=-1;
		for(int i=0;i<n;i++){
			LIS(i);
		}
		for(int i=0;i<n;i++) res=max(res,save[i]);
		cout<<res;	
	}
	
}
