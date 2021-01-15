#include<stdio.h>
int main(){
	int T,i, a[100],b[100],c[100];
	do{scanf("%d",&T);
	}while(T<0||T>10);
	for(i=0;i<T;i++) {
		scanf("%d %d",&a[i],&b[i]);
		c[i]=a[i]+b[i];}
	for(i=0;i<T;i++){
		printf("%d\n",c[i]);}
	return 0;
	}
