#include<bits/stdc++.h>
using namespace std;

int main(){
	int T,n,m;	int a[101],b[101];	int res;	
	cin>>T;	
	while(T--){
	set<int> A;	set <int> B; set<int> C;
	res=0; 
	cin>>n;	for(int i=1;i<=n;i++){
		cin>>a[i]; A.insert(a[i]);C.insert(a[i]);
	}
	
	cin>>m;	for(int i=1;i<=m;i++){
		cin>>b[i]; B.insert(b[i]);C.insert(b[i]);
	}  
	cout<<A.size()+B.size()-C.size();
	A.clear();B.clear();C.clear();
	}
}
