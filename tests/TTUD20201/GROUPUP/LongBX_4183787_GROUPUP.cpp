#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main()
{
	int T;
	int n[10],a[100][100],sum[10],ans[10];
	cin>>T;
	if (T==0) return 0;
	for (int i=0; i<T; i++)
	{
		cin>>n[i];
		for (int j=0; j<n[i]; j++)
			{
			cin>>a[i][j];
			sum[i]=sum[i]+a[i][j];
			ans[i]=sum[i]*2;
		}
	}
	for (int i=0; i<T; i++)
	cout<<ans[i]<<endl;
}
