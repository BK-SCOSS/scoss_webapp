#include<stdio.h>

int main()
{
	long long int Q,N[10000],T[10000],TS[10000],d[10000],i,j;
	do
	{
		scanf("%lli",&Q);
	}while(Q<0);
	for(i=0;i<Q;i++)
	{
		d[i]=0;
		do
		{
		scanf("%lli",&N[i]);
		}while(N[i]<0);
		T[i]=N[i]*(N[i]+1)*(N[i]+2);
		TS[i]=T[i]*T[i];
		for(j=1;j<T[i];j++)
		{
			if((TS[i]%j==0)&&(T[i]%j)!=0)
			d[i]++;
		}
	}
	for(i=0;i<Q;i++)
	{
		printf("%lli\n",d[i]);
	}
}
