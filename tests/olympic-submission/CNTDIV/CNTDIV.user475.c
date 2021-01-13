#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fi = fopen("input.txt", "r");
	FILE *fo = fopen("output.txt", "w");
	int n;
	fscanf(fi, "%d", &n);
	int a[n];
	long b[n];
	long c[n];
	int *count;
	count= (int *) calloc(n,sizeof(int));
	int i,j;
	for(i=0;i<n;i++){
		fscanf(fi,"%d",&a[i]);
		b[i]=a[i]*(a[i]+1)*(a[i]+2);
		c[i]=b[i]*b[i];
		for(j=1;j<b[i];j++){
			if(c[i]%j==0&&b[i]%j!=0) count[i]+=1;
		}
	}
	for(i=0;i<n;i++){
		fprintf(fo,"%d\n",count[i]);
	}
	fclose(fi);
	fclose(fo);
	return 0;
	
}
