#include <iostream>
#include <math.h>
using namespace std;
int dem_uoc (int n)
{
	int dem=0,e;
	
	for(int i=1;i<pow(n,0.5);i++)
		{
			if(n%i==0)
			 {
			   e=i*i;
				if(n%e!=0) dem++;
		}}
	return dem;
}
int main()
{
	int d,a;
	unsigned long N,t;
	cin >> a;
	while(a--)
	{
	cin >> N;
	t= pow(N,2)*pow(N+1,2)*pow(N+2,2);
	d= dem_uoc(t);
	cout << d;
	}
}
