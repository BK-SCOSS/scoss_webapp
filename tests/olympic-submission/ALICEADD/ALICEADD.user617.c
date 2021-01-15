#include<stdio.h>
int main()
{
	int T;
	long i,a,b,c[100];
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%ld%ld",&a,&b);
		c[i]=a+b;
	}
	for(i=1;i<=T;i++)
	{
		printf("%d\n",c[i]);
	}
	return 0;
}
