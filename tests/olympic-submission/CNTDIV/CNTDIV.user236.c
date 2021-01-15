#include <stdio.h>
int main(){
	int n,q,i,j, m[10];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m[i]);
	}
	
int k = 0;
	for(i=0;i<n;i++){
		q = m[i]*(m[i]+1)*(m[i]+2);
		for(j=1;j<=(q*q);j++){
			if((q*q)%j==0 && (j<q) && (q%j)!=0){
				k++;
			}	
		}
		printf("%d\n",k);
		k = 0;
	}
	return 0;
}
