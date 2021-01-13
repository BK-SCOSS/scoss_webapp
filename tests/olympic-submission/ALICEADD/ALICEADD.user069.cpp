#include<stdio.h>
int main()
{
	int m, i;
    scanf("%d",&m);
    int a[m][2];
    for(i=0;i<m;i++)
       scanf("%d %d", &a[i][0],&a[i][1]);
    for(i=0;i<m;i++)
	   printf("%d\n",a[i][0]+a[i][1]);   
	return 0; 
}
