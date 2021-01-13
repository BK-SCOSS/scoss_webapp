#include <iostream>

using namespace std;

int main()
{
	int t,count;
	unsigned long long int a[10],b[10];
	cin>>t;
	for ( count=0 ; count<t ; count++ )
	{
		cin>>a[count]>>b[count];
	}
	
	for ( count=0 ; count<t ; count++ )
	{
		cout<<a[count]+b[count]<<"\n";
	}
	return 0;
}
