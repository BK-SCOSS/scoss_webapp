#include<stdio.h>
int main(){
	int i,j,N,T,Q,t,n=0;
	scanf("%d\n",&Q);
	for(i=1;i<=Q;i++){
		scanf("%d\n",&N);
		T=N*(N+1)*(N+2);
		t=T*T;
		for(j=1;j<T;j++){
			if((t%j==0)&&(T%j!=0)) n=n+1;	
		}
		printf("%d",n);
	}
	
}
