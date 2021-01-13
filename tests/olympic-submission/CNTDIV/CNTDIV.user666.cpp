#include<stdio.h>


int main(){
	int T,N,i,Q,count=0,j,a[1000],dem=0,k,check=1,b[1000];
	scanf("%d",&Q);
	for(i=0;i<Q;i++){
		count=0;
		dem=0;
		scanf("%d",&N);
		T=N * (N + 1) * (N + 2);
		for(j=2;j<T;j++){
			if(T%j==0){
				a[count]=j;
				count++;
			}
		}
		for(j=2;j<T;j++){
			check=1;
			if((T*T)%j==0){
				for(k=0;k<count;k++){
					if(j==a[k]){
					
					check=0;
					break;
				}
				}
				if(check==1)
				dem++;
			}
		}
		b[i]=dem;	
	}
	for(i=0;i<Q;i++){
		printf("%d\n",b[i]);
	}
	return 0;
}

