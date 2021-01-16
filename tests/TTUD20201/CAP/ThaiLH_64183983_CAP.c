#include <stdio.h>
#include <stdlib.h>
run(int a[], int b[], int n, int m){
	int count=0;
	int p,q;
	for(p=0;p<n;p++){
		for(q=0;q<m;q++){
			if (b[q]==a[p]) count++;
		}
	}
	return count;
}
int main() {
int m,n,i,j,t;
//
scanf("%d",&t);
int *ketqua= (int*)(malloc(sizeof(int)*t));
int l;

for(l=0;l<t;l++){
    scanf("%d",&n);
	int*a=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
	scanf("%d",&a[i]);
	}
//
    scanf("%d",&m);
	int*b=(int*)malloc(sizeof(int)*m);
	for(j=0;j<m;j++){
	    scanf("%d",&b[j]);
	}
//
	ketqua[l]=run(a,b,n,m);
}
int z;
for (z=0;z<l;z++){
    printf("%d",ketqua[z]);
}
return 0;
}
