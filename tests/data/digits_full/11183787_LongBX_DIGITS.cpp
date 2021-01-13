#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int hust(long long k)
{
	int dem=0,j[10000],l[10000];
	if (k<10010) return 0;
	if (k>109998) return 0;
	if (k%2==1) return 0; else return 8;
	{
	for (int i=1000;i<=9999;i++)
		{
			j[i]=i;
			l[i]=k-i;
		}
}
}
int main()
{
	int T,n[50];
	cin>>T;
	for (int i=0;i<T;i++)
	cin>>n[i];
	
	for (int i=0;i<T;i++)
	{
		cout << hust(n[i]) <<endl;
	}
}
