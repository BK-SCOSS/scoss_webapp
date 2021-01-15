#include<stdio.h>

int main(){
	int T, a[11],b[11],i;
	do scanf("%d",&T);
		while(T>10||T<0);
	for (i=0;i<T;i++) {
		scanf("%d %d\n",&a[i],&b[i]);
	}
	for (i=0;i<T;i++) {
		printf("%d\n",a[i]+b[i]);
	}
	return 0;
	
	
}
