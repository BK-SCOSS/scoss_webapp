#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n,d=0;
	unsigned long a;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		d=0;
		cin>>a;
		unsigned long t=a*(a+1)*(a+2);
		a=t*t;
		for (unsigned long i=2; i<t; i++)
			if (t%i!=0 && a%i==0) d++;
		cout<<d<<endl;
	}
}
