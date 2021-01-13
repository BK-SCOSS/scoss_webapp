#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	long n,t, bpt; int souoc,i=1;
	scanf("%d",&n);
	t=n*(n+1)*(n+2);
	bpt=t*t;
	souoc=0;
	
	for( i;i<t;i++)
	{if(bpt%i==0 && t%i!=0)
	 souoc++;
	}
printf("%d",souoc);
	return 0;
}
