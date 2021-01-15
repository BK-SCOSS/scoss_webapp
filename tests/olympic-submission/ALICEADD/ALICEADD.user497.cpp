#include<stdio.h>

int main(){
	int T,a,b,i;
	int sum[10];
	do scanf("%d",&T);
	while((T<0)&&(T>10));
	for(i=0;i<T;i++){
		scanf("%d%d",&a,&b);
		sum[i]=a+b;
	}
	for(i=0;i<T;i++){
		printf("%d\n", sum[i]);
	}
	return 0;
}
