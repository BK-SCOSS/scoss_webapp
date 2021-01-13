#include<stdio.h>

int main () {
	int n;
	printf("1\n");
	scanf("%d",&n);
	int T=n*(n+1)*(n+2);
	int t=T*T,i,c=0;
	for (i=1;i<T;i++) {
		if(t%i==0 && T%i!=0) {
			c++;
		}
	}
	printf("%d",c);
	return 0;
}
