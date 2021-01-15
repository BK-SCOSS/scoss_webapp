#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fi = fopen("input.txt", "r");
	FILE *fo = fopen("output.txt", "w");
	int n;
	fscanf(fi, "%d", &n);
	int *a;
	a = (int *) malloc(2*n*sizeof(int));
	int i;
	for(i=0;i<2*n;i+=2){
		fscanf(fi,"%d %d",a+i,a+i+1);
		fprintf(fo,"%d",a[i]+a[i+1]);
	}
	fclose(fi);
	fclose(fo);
	return 0;
	
}
