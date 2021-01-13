#include <iostream>
#include <stdio.h>

using namespace std;
int  demkq(int N){
	unsigned long long int T,dem=0,i;
	T=N*(N+1)*(N+2);
	for (i=1;i<T;i++)
	{ if (((T*T)%i==0)&&(T%i!=0))
		dem++;
	}
	return dem;
}
int main(){	
	int Q,n[1000000];
	cin>>Q;
	for (int i=0;i<Q;i++){
		cin >>n[i];
	}
	for (int i=0;i<Q;i++)
		cout <<demkq(n[i]) <<"\n";
	return 0;
	}
