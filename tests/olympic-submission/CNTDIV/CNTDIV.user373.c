#include<stdio.h>
#include<math.h>
unsigned long long n,i,j,Q,T,result;

int main(){
	if(scanf("%llu",&Q)==1);
	for(i=1;i<=Q;i++){
		result =0;
		if(scanf("%llu",&n)==1);
		T=n*(n+1)*(n+2);
		for(j=1;j<T;j++){
			if((T%j!=0)&&((T*T)%j==0)) result+=1;
		}
		printf("%llu\n",result);
	}return 0;
}
