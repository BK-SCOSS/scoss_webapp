#include<iostream>
using namespace std;
int main(){
	long long Q,N,T,X;
	cin>>Q;
	long long *a=new long long(Q);
	for(long long i=0; i<Q;i++) cin>>a[i];
	for(long long i=0;i<Q;i++){
		T=a[i]*(a[i]+1)*(a[i]+2);
		X=T*T;
		long long dem=0;
		for(long long i=1; i<T;i++){
			if(T%i!=0 && X%i==0) dem=dem+1;}
		cout<<dem<<endl;
		}
	return 0;
}
	
	
