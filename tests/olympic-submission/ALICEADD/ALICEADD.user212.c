#include<stdio.h>

int main()
{
	unsigned int k=0,c[13],i;
	unsigned long a,b;
	scanf("%d",&k);
	for(i=0;i<=k-1;i-=-1)
	{
		scanf("%d",&a);
		scanf("%d",&b);
		c[i]=a+b;
	}
	for(i=0;i<=k-1;i-=-1)
	{
		printf("\n%d",c[i]);
	}
}
