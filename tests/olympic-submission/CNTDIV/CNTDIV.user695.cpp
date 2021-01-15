#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int N;
	int T;
	int Q=0 ;
	cin>>N;
	T = N*(N + 1) * (N + 2);
	for(int i = 1; i < T; i++)
	{
		if(T*T % i == 0 && T % i != 0)
			Q += 1;
	}
	cout<<Q;
	return 0;
}
