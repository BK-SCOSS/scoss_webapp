#include <stdio.h>
#include <math.h>
int main(){
	int n, t,t2, i,j,k[1000],l[1000],m,o;
	scanf("%d",&n);
	t=n*(n+1)*(n+2);
	t2=t*t;
	m=0;
	o=0;

	for (i=1;i<=sqrt(t);i++){if ((t%i)==0){m++;} }
	for (j=1;j<t;j++){
		if ((t2%j)==0) {o++;}
	}
	printf("%d",o-m);
	return 0;
}
