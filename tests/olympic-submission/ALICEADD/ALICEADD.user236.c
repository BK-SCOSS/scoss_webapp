#include <stdio.h>

int main(){
	unsigned long long a,b,m[10];
	int i,n;
	scanf("%d",&n);
	while(n<0||n>10) scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%llu %llu",&a,&b);
		m[i]= a+b;
	}
	for(i=0;i<n;i++){
		printf("%llu\n",m[i]);
	}
	return 0;
}
