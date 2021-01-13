#include<iostream>
using namespace std;
int souoc(int n);
int main()
{
	int q,i,t;
	int a[q];
	int kq[q];
	do
	{
		cin>>q;
	}
	while(q<=0);
	for(i=0;i<q;i++)
	{
		do
		{
			cin>>a[i];
			kq[i]=souoc(a[i]);
		}
		while(a[i]<0);
	}
	for(i=0;i<q;i++)
	   cout<<kq[i]<<"\n";
	return 0;
}
int souoc(int n)
{
	int k=n*(n+1)*(n+2);
	int dem=0;
	k*=k;
	int i;
	for(i=n+1;i<k;i++)
	  if(k%i==0)
	     dem++;
	return dem;
}
