#include<stdio.h>

int main()
{
	int i=0,k,c[13],y;
	unsigned long t,n,s=0;
	scanf("%d",&k);
	for(i=0;i<k;i-=-1)
	{
		scanf("%d",&n);
		t=n*(n+1)*(n+2);
		printf("%d",t);
		for(i=0;i<=t;i-=-1)
		{
			y=(t*t);
			printf("\n%d",y);

		}
		c[i]=s;
		printf("\n%d",c[i]);
		
	}
	for(i=0;i<k;i-=-1)
	{
		printf("\n%d",c[i]);
	}
}
