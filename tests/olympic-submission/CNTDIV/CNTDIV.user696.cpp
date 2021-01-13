#include <iostream>
#include <vector>
using namespace std ;

void uoc(int k[],int n)
{
	for(int i=2;i<=n;i++)
	{
		if(n%i==0)
		{
			k[i]++;
			n=n/i;
			i--;
		}
	}
}
int main()
{
	int q;
	cin>>q;
	vector<unsigned long long int> ketqua ;
	int s[q];
	for(int i=0;i<q;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<q;i++)
	{
		int luukq[s[i]+3];
		for(int j=0;j<=s[i]+2;j++)
		{
			luukq[j]=0;
		}
		uoc(luukq,s[i]);
		uoc(luukq,s[i]+1);
		uoc(luukq,s[i]+2);
		unsigned long long int souoc1=1,souoc2=1;
		for(int j=0;j<=s[i]+2;j++)
		{
			souoc1= souoc1*(luukq[j]+1);
		}
		for(int j=0;j<=s[i]+2;j++)
		{
			souoc2= souoc2*(2*luukq[j]+1);
		}
		ketqua.push_back((souoc2+1)/2-souoc1);
	}
	for(int i=0;i<ketqua.size();i++)
	{
		cout<<ketqua[i]<<endl;
	}
}
