#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, T, count,i,j, t[100];
	long long a[100], b[100];
	int m;
	cin>>T;
	for(int u=0;u<T;u++){
		count=0;
		cin>>n;
		for(i = 0; i<n;i++){
			cin>>a[i];
		}
		cin>>m;
		for(int i = 0; i<m;i++){
			cin>>b[i];
		}
		for(i = 0; i<n;i++){
			for(j=0;j<m;j++){
				if(a[i] == b[j]){
					count++;
					break;
				}
			}
		}
		t[u] = count;
	}
	for(i=0;i<T;i++){
		cout<<t[i]<<"\n";
	}
	return 0;
}
