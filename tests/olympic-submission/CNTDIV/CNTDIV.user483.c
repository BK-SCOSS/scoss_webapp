#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int souoc(unsigned int n); 
int main(){
	int i;
	unsigned int n;
	scanf("%d",&n);
	unsigned int *Q=(unsigned int*)malloc(n*sizeof(unsigned int));
	for (i=0;i<n;i++)
	{
		
		scanf("%d",Q+i);
	}
	for (i=0;i<n;i++)
	    printf("%d",souoc(*(Q+i)));
	free(Q);
	return 0;	
}
int souoc(unsigned int n)
{
	int m=0,i;
	unsigned int T=n*(n+1)*(n+2);
	for (i=1;i<T;i++)
		if ((((T*T)%i)==0)&&((T%i)!=0))
			{
				m=m+1;
			}
	return m;
}
