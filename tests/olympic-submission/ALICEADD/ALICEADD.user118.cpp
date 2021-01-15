#include <stdio.h>
int main(){
	int t;
	unsigned long long int a,b,sum[t];
	do {scanf("%d",&t);
	}
	while (t<0||t>10);
	for (int i=0;i<t;i++){
		scanf("%llu%llu",&a,&b);
		sum[i]=a+b;
	}
	for (int i=0;i<t;i++){
		printf("%llu",sum[i]);
	}
	return 0;
}
