#include<stdio.h>


int main(){
	int T,i,a[100];
	scanf("%d",&T);
	for(i=0;i<=2*T-1;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<=2*T-1;i+=2){
		printf("%d\n",a[i]+a[i+1]);
	}
	return 0;
}

