#include<stdio.h>
int uoc(int a){
	int dem=0;
	for(int i=1;i<a;i++){
		if((a*a)%i==0&&a%i!=0)
			dem++;
	}
	return dem;
} 
   int main()
{
	int a,k,b,q;
		scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&a);
		b=a*(a+1)*(a+2);
		}
	for(int i=0;i<q;i++){
		k=uoc(b);
		printf("%d\n",k);
	}
	return 0;
}
