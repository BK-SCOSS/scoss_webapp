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
	int a[100000],k,b[1000000],q;
		scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]*(a[i]+1)*(a[i]+2);
		}
	for(int i=0;i<q;i++){
		k=uoc(b[i]);
		printf("%d\n",k);
	}
	return 0;
}
