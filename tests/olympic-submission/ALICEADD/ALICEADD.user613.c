#include<stdio.h>
int main(){
  int n,i;
  int a[10],b[10];
  FILE *f1,*f2;
  f1 = fopen("input.txt","r");
  fscanf(f1,"%d",&n);
  for(i=0;i<n;i++){
  	fscanf(f1,"%d %d",&a[i],&b[i]);
  }
  fclose(f1);
  f2 = fopen("output.txt","w");
  for(i=0;i<n;i++){
  	fprintf(f2,"%d\n",a[i]+b[i]);
  }
  fclose(f2);
return 0;
}

