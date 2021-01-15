#include<stdio.h>
#include<math.h>
int main(){
	int n,a,b,sum[1000];
	do{
		scanf("%d",&n);
	}while(n<0&&n>10);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		sum[i]=a+b;
	}
	for(int i=0;i<n;i++){
		printf("%d ",sum[i]);
	}
	return 0;
}
