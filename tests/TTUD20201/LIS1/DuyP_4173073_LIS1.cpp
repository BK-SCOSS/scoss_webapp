#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int o=1;o<=T;o++){
		int n;
		cin >> n;
		int a[100001];
		int f[100001];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		a[0] =0;
		f[0] = 0;
		for(int i=1;i<=n;i++){
			f[i] = 1;
			for(int k = i-1;k>=1;k--){
				if(a[i]==a[k]+1){
					f[i] = f[i] > (f[k]+1) ? f[i] : f[k]+1;
				}
			}
		}

		int max = 1;
		for (int i = 1; i <=n ; i++)
		{
			if(f[i]>=max) max = f[i];
		}
		cout<<max<<endl;
	}
}