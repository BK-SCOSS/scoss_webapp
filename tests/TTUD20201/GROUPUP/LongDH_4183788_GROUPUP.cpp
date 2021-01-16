#include<bits/stdc++.h>
using namespace std;

int main(){
	int T,n,m;	int a[101],b[101];	int res;	
	cin>>T;	
	while(T--){
	res=0; 
	vector <int> A;
	vector <int> B;	
	cin>>n;	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<i;j++){
			if(a[i]!=a[j]) A.push_back(a[i]);
		}
	}
	cin>>m;	for(int i=1;i<=m;i++){
		cin>>b[i];
		for(int j=1;j<i;j++){
			if(b[i]!=b[j]) B.push_back(b[i]);
		}
	}  
	for(int i=0;i<A.size();i++){
		 for(int j=0;j<B.size();j++){
			if(A[i]==B[j]){
				res++;
				break;
			}
		}
	}
	A.clear();B.clear();
	cout<<res;
	}
}
