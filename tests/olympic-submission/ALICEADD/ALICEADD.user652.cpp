#include<stdio.h>
int main()
{
	int T,a[10][2];
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d %d",&a[i][1],&a[i][2]);
	}
	for(int i=0;i<T;i++)
	{
		printf("%d\n",a[i][1]+a[i][2]);
	}
	return 0;
}
