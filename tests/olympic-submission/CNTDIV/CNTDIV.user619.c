#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
  int n=1,i,j;
  int a,b;
  int dem=0;
  FILE *f1,*f2;
  f1 = fopen("input.txt","r");
  f2 = fopen("output.txt","w");
  fscanf(f1,"%d",&n);
  for(i=0;i<n;i++){
  	fscanf(f1,"%d",&a);
  	b=a*(a+1)*(a+2);
  	for(j=2;j<b;j++){
  		if( (b*b)%j == 0 && b%j != 0) dem++;
	  }
	fprintf(f2,"%d\n",dem);  
  }
  fclose(f2);
  fclose(f1);
return 0;
}
