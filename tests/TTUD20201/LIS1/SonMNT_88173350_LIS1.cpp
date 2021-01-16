#include<stdio.h>
int a[100000],n,map[100000],ketqua[100],d[100000];
void clear(){
	
}
void xuly(int k){
	int kq=1;
	for(int i=n-2;i>=0;i--){
		int tg=a[i];
		for(int k=i+1;k<n;k++){
			if(a[k]-tg==1){
				if(d[k]==1){
					kq=kq+map[k];
					break;
				}
				else{
				kq++;
				tg=a[k];
				}
				
			}
		}
		if(kq>ketqua[k]){
			ketqua[k]=kq;
		}
		map[i]=kq;
		d[i]=1;
		kq=1;
	}
}
main(){
	int m;
	scanf("%d",&m);
	for(int k=0;k<m;k++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		xuly(k);
	}
	for(int k=0;k<m;k++){
		printf("%d",ketqua[k]);
	}
	
}
