#include<iostream>
using namespace std;
int main()
{
	int T,a,b,i;
	int k[T];
	do
	{
		cin>>T;
	}
	while(T>10);
	for(i=0;i<T;i++)
	{
		cin>>a;
		cin>>b;
		k[i]=a+b;
	}
	for(i=0;i<T;i++)
	  cout<<k[i]<<"\n";
	return 0;
}
