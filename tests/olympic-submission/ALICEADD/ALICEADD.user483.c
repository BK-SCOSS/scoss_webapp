#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int i;
	unsigned int T,X1[100],X2[100];
	scanf("%d",&T);
	for (i=0;i<T;i++)
	{
		scanf("%d %d",&X1[i],&X2[i]);
			}
		
	for (i=0;i<T;i++)
		printf("%d \n",(X1[i]+X2[i]));
	return 0;	
}
