#include<bits/stdc++.h>
using namespace std;
void interest(int* a,int& n){
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]==a[j]){
				for(int k=i;k<n;k++){
					a[k]=a[k+1];
					n--;
					i--;
				}
			}
		}
	}
}
main(){
	int t;
	cin>>t;
	int n,m;
	int count=0;
	cin>>n;
	int* a = new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	int* b = new int[m];
	for(int j=0;j<m;j++){
		cin>>b[j];
	}
	interest(a,n);
	interest(b,m);
	for( int i=0 ;i <n;i++){
		for(int j=0 ;j < m;j++){
			if( a[i] == b[j]){
				count++;
			}
		}
	}
	delete[] a;
	delete[] b;
	cout<<count<<endl;
	return 0;
}
