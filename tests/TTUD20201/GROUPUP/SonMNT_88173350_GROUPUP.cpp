#include<stdio.h>
int a[1000000],k;
int ketqua[100000];
void xuly(int k,int k1){
	if(k==1){
	}
	else{
		int tg=0,max=0;
		for(int i=0;i<k-1;i=i+2){
			a[tg]=a[i]+a[i+1];
			
			if(a[tg]>max){
				max=a[tg];
			}
			tg++;
		}
		ketqua[k1]=ketqua[k1]+max;
		if(k%2==1){
			a[tg]=a[k-1];
			tg++;
		}
		xuly(tg,k1);
	}
	
}
main(){
	int n;
	scanf("%d",&n);
	for(int m=0;m<n;m++){
		scanf("%d",&k);
		for(int i=0;i<k;i++){
			scanf("%d",&a[i]);
		}
		xuly(k,m);
		for(int i=0;i<n;i++){
			printf("%d",ketqua[i]);
		}
		
	}
	
}
