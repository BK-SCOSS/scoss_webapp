#include<stdio.h>
#include <math.h>
int main(){
	int n,dem1=0,dem2=0,dem3;
	unsigned long long int t,a1[t],a2[t],Q,ketqua[Q];
	do{scanf("%d",&Q);
	}
	while (Q<=0);
	for(int d=1;d<=Q;d++){
	
	do {scanf("%d",&n);}
	while (n<0);
	t=n*(n+1)*(n+2);
	for (int i=1;i<=t;i++){
		if(t%i==0){
		a1[i]=i;dem1++;}
	}
	for (int j=1;j<=t*t;j++){
		if((t*t)%j==0){
		a2[j]=j;dem2++;}
		}
	for (int m=0;m<dem2-1;m++){
		for (int n=0;dem1-1;n++){
			if(a1[m]<t && a1[m]!=a2[n])dem3++;
		}
	}
 for (int u=0;u<Q;u++){
 	ketqua[u]=dem3;
 }
	}
	for (int u=0;u<Q;u++){printf("\n%llu",ketqua[u]);}
	return 0;
}
