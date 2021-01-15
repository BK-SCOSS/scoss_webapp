#include <stdio.h>
int main(){
	int a[10000], b[10000],c[10000], n, i,j;
	scanf("%d\n",&n);
	for (i=0;i<n;i++){
		scanf("%d%d\n",&a[i],&b[i]);
		c[i]=a[i]+b[i];
		}
	for (j=0;j<n;j++) printf("%d\n",c[j]);
}
