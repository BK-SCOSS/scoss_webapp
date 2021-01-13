#include<iostream>
using namespace std;
void calculate()
{
	int n;
	int t,t1;
	int count=0;
	cin>>n;
	t=n*(n+1)*(n+2);
	t1=t*t;
	for(int i=2;i<t;i++)
	if((t1%i==0)&&(t%i!=0))count++;
	cout<<count<<'\n';
}
int main()
{
	int q;
	cin>>q;
	int i;
	for(i=0;i<q;i++);
	calculate();
	
}
