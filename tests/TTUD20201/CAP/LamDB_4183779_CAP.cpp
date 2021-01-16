#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	for (int i=0;i<T;i++){
		int m,n;
		unsigned long long a[100],b[100];
		cin>>n;
		for (int j= 0;j<n ;j++) cin>>a[j];
		cin>>m;
		for (int k=0;k<m;k++) cin>>b[k];
		int count=0;
		
        for (int j=0;j<n-1;j++)
        	for(int k=0;k<m;k++)
        		if (a[j]==b[k]) {
        			count++;
        			break;
				}
	
		cout<<count;
	}
	return 0;
}
