#include<stdio.h>

main()
{
	int N,dem=0,t;
	long T,i;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&N);
		T=N*(N+1)*(N+2);
		for ( i=4; i<T; i++)
		{
			if (T%i==0) continue;
			else if (T*T%i==0) dem++;
		}
	}
	printf("%d",dem);
}
