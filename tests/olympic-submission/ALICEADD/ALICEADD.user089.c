#include<stdio.h>

int main () {
	int T;
	scanf ("%d",&T);
	while (T>10 || T<=0) {
		scanf ("%d",&T);
	}
	int a[T][2],b[T];
	int i;
	for (i=0;i<T;i++) {
		scanf ("%d%d",&a[i][0],&a[i][1]);
		b[i]=a[i][0]+a[i][1];
	}
	for (i=0;i<T;i++) {
		printf("%d\n",b[i]);
	}
	return 0;
}
