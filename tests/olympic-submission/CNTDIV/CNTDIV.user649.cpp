#include<iostream>
using namespace std;
int main(){
	long long Q,N,t,T,dem=0,i;
	
	cin>>Q;
	long double *c=new long double{0};
	
	while (Q>0){
		cin>>N;
		t=N*(N+1)*(N+2);
		T=t*t;
		for(i=2;i<t;i++){
			if(t%i!=0&&T%i==0) c[dem]+=1;
		}
		dem+=1;
		Q-=1;
	}
	for(i=0;i<dem;i++){
		if(i!=(dem-1)) cout<<c[i]<<"\n";
		else cout<<c[i];
	}
	return 0;
}
