#include<iostream>
#include<cmath>
using namespace std;
int PT,PT2,k;
void dem (int N)
{
	int L = N;
	if (N>1) for (int i = 2; i<=N; i++)
	{
		k = 0;
		if (L%i == 0)
		{
			while (L%i == 0)
			{
				k++;
				L = L/i;
			}
			PT = PT*(k+1);
			PT2 = PT2*(2*k+1);
			
		}
		if (L<2) break;
	}
}
int main()
{
	int N;
	int Q;
	cin>>Q;
	int a[Q+1];
	for (int i = 1; i<=Q; i++)
	{
		cin>>N;
		PT = 1; PT2 = 1;
		if (N%2 != 0) 
		{
			dem (N); dem (N+1); dem (N+2);
			a[i] = (PT2 + 1)/2 - PT;
		}
		if (N%2 == 0)
		{
			int p= 0;
			int x = N;
			int y = N+2;
			while (x%2 == 0)
			{
				x= x/2;
				p++;
			}
			while (y % 2 == 0)
			{
				y = y/2;
				p++;
			}
			dem (x); dem (N+1); dem(y);
			PT2 = PT2*(2*p+1);
			PT = PT*(p+1);
			a[i] = (PT2 + 1)/2 - PT;
		}
	}
	for (int i = 1; i<=Q; i++) cout<<a[i]<<endl;
	exit(0);
}
