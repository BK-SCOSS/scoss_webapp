#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	for (int i=0; i<T; i++){
		int n;cin>>n;
		unsigned long long a[10000];
		for (int j=0;j<n;j++) cin>>a[j];
		int max=0;
		for(int j=0;j<n-1;j++)
		{
		int k=j+1;int count=1;int now=a[j];
		while(k<n){
			if(a[k]==now+1) {now=a[k];
			count++;}
			k++;
		}
		if(max<count) max=count;}
		cout<<max;
	}
	return 0;
}
