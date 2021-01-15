#include <stdio.h>
int main(){
	unsigned long long a,b;
	int n,i;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	 {scanf("%llu%llu",&a,&b);
	  printf("%llu\n",a+b);
	 };
	return 0;
}
