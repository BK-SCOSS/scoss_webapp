#include<stdio.h>
int demUoc1(int a){
	int i;
	int count=0;
	for(i=1;i<=a;i++){
		if(a%i==0){
		count++;
		}
	}
	return count;
}
int demUoc2(int a){
	int i;
	int count=0;
	for(i=1;i<=a;i++){
		if(a*a%i==0){
		count++;
		}
	}
	return count;

}
main(){
	int total,n[100],i;
	scanf("%d",&total);
	for(i=0;i<total;i++){
		scanf("%d",&n[i]);
		int a=n[i]*(n[i]+1)*(n[i]+2);
		printf("%d",demUoc2(a)-demUoc1(a));
	}
	
	return 0;
}
