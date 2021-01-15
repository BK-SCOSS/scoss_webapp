#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	int i,j;
	unsigned int kt,n,m,K,tg,T,max;
	scanf("%d %d",&n,&K);
	unsigned int *s=(unsigned int*)malloc(n*sizeof(unsigned int));
	unsigned int *d=(unsigned int*)malloc(n*sizeof(unsigned int));
	unsigned int *r=(unsigned int*)malloc(n*sizeof(unsigned int));
	for (i=0;i<n;i++)
	{		
		scanf("%d %d %d ",s+i,d+i,r+i);
	}
	m=n;
	while (m!=1)
	{
		for (i=0;i<m-1;i++)
			if (*(s+i)>*(s+i+1))
			{
				tg=*(s+i+1);
				*(s+i+1)=*(s+i);
				*(s+i)=tg;
				
				tg=*(d+i+1);
				*(d+i+1)=*(d+i);
				*(d+i)=tg;
				
				tg=*(r+i+1);
				*(r+i+1)=*(r+i);
				*(r+i)=tg;
			}
		m=m-1;
	}
	max=0;
	for (i=0;i<n-1;i++) 
		{
			T=*(r+i);
			kt=*(s+i)+*(d+i)-1;
			for (j=i+1;j<n;j++)
				if ((kt+K)<(*(s+j)))
				{
				     kt=*(s+j)+*(d+j)-1;
				     T=T+*(r+j);
			}
			if (T>max)
			    max=T;
		}
	printf("%d",max);
	free(s);
	free(d);
	free(r);
	return 0;	
}

