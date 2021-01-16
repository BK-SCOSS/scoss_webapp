#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int kq=0;
		int n,m,a[100001],b[100001];
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>b[i];
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i]==b[j]){
					kq++;
					break;
				}
			}
		}
		cout<<kq<<endl;
		return 0;
	}
}
