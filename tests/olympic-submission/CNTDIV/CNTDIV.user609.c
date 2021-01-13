#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i;
	int dem=0;
	scanf("%d",&n);
	int t=n*(n+1)*(n+2);
	int k=t*t;
	for (i=1;i<t;i++){
		if ((k%i==0)&&(t%i!=0)) dem++;
	}
	printf("%d",dem);
	return 0;
}
