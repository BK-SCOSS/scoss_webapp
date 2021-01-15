#include<stdio.h>

int main()
{
	unsigned long int T,a[10],b[10],i;
	do
	{
	scanf("%lu",&T);
	}while(T<0||T>10);
	for(i=0;i<T;i++)
	{
		do
		{
			scanf("%lu %lu",&a[i],&b[i]);
		}while(a[i]<0&&b[i]<0);
	}
	for(i=0;i<T;i++)
	{
		printf("%lu\n",a[i]+b[i]);
	}
}
