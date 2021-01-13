#include<stdio.h>
int main()
{
	long Q;
	long i,T,N,a,b,j,k;
	scanf("%ld",&Q);
	long c[Q];
	for(i=1;i<=Q;i++)
	{
		c[i]=0;
		scanf("%ld",&N);
		T=N*(N+1)*(N+2);
		k=T*T;
		for(j=2;j<=T;j++)
		{
			if(T%j!=0&&k%j==0) c[i]++;
		}
	}
	for(i=1;i<=Q;i++)
	{
		printf("%d\n",c[i]);
	}
	return 0;
}
