#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	unsigned long long int a,b,x[T+1];
	for (int i = 1; i<= T; i++)
	{
		cin>>a>>b;
		x[i] = a + b;
	}
	for (int i = 1; i<= T; i++) 
	{
		cout<<x[i]<<endl;
	}
	return 0;
}
