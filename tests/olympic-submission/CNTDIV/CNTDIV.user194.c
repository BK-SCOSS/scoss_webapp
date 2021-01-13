#include <stdio.h>
#include <math.h>
int main(){
	int n, t, i,j,k[1000],l[1000];
	scanf("%d",&n);
	t=n*(n+1)*(n+2);
	

	for (i=1;i<=sqrt(t);i++){if ((t%i)==0){k[i]=i;} }
	for (j=1;j<t;j++){
		if (((t*t)%j)==0) {l[j]=j;}
	}
	
}
