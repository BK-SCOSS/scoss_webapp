#include <bits/stdc++.h>

using namespace std;
int n;
int a[1000003];

void lis1(int *a){
	int res=0;
	for(int i=1;i<=n;i++){
		int k=a[i];
		int cnt=0;
		for(int j=i;j<=n;j++){
			if(a[j]==k){
				k++;
				cnt++;
			}
		}
		res=max(cnt,res);
	}
	cout<<res;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		lis1(a);
	}



	return 0;
}

