#include<stdio.h>

int main()
{
	int n,i;
	unsigned long int a[20], b[20] ;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%lu %lu", &a[i], &b[i]);
	}
	for (i=0; i<n; i++)
		printf("%lu", a[i]+b[i]);
}


