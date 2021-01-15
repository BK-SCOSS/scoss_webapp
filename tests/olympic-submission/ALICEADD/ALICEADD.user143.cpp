#include<iostream>
using namespace std;
void compute()
{
	unsigned long long int a,b;
	do{
		cin>>a;
	}while(a<0);
	do{
		cin>>b;
	
	}while(b<0);
	cout<<a+b<<'\n';
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		compute();
}

