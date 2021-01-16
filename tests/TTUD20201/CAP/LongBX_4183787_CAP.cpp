#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main()
{
	int T,z=1;
	int n[10], m[10],ans[10];
	long a[100][100],b[100][100];
	cin>>T;
	for (int i=0; i<T; i++)
	{
		cin>>n[i];
		for (int j=0; j<n[i]; j++)
			{cin>>a[i][j];
			}
		cin>>m[i];
		for (int j=0; j<m[i]; j++)
			{cin>>b[i][j];
			}
		for (int j=0; j<n[i]; j++)
			for (int k=j+1; k<n[i]; k++)
			{
				if (a[i][j]==a[i][k]) 
				{a[i][k]=a[i][k]+z*6996;
				z++;
				}
			}
		for (int j=0; j<n[i]; j++)
			for (int k=j+1; k<m[i]; k++)
			{
				if (b[i][j]==b[i][k]) 
				{b[i][k]=b[i][k]+z*6996;
				z++;
				}
			}
		for (int j=0; j<n[i]; j++)
			for (int k=0; k<m[i]; k++)
			{
				if (a[i][j]==b[i][k]) ans[i]++;
				
			}
		cout<<ans[i]<<endl;
		
	}
	
}
