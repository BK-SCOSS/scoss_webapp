#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	int n, m;
	int a[101], b[101];
	
	cin>>T;
	for(int i=0; i<T; i++){
		int ketqua=0;
		cin>>n;
		for(int j=0; j<n; j++){
			cin>>a[j];
		}
		cin>>m;
		for(int j=0; j<m; j++){
			cin>>b[j];
		}
		
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				if(a[j]==b[k]) ketqua=ketqua+1;
			}
		}
		cout<<ketqua;
	}
	return 0;
}
