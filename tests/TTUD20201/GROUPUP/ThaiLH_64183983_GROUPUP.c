#include <stdio.h>
#include <stdlib.h>

int main() {
	int T;
	scanf("%d",&T);
while(T--){
    int n;
    scanf("%d",&n);
    int*a=(int*)malloc(sizeof(int)*n);
    int j;
	for(j=0;j<n;j++){
		scanf("%d",&a[j]);
	}
	int*b=(int*)malloc(sizeof(int)*1001);
    int res=0;
	
	while (n>1){
		int h=0;
		int t=0;
		int i;
		for(i=1;i<n;i+=2){
			h++;
			b[h]=a[i]+a[i+1];
		}
		if(n%2==1){
			h++;
			b[h]=a[n];
		}
		n=h;
		for(i=1;i<=n;i++){
			a[i]=b[i];
			t=max(t,b[i]);
		}
		res+=t;
	}
	printf("%d",&res);
}
	return 0;
}
