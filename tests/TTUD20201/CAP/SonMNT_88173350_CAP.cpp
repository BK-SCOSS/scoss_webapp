#include<stdio.h>
/*string a = " bananinn ",
	b = " kaninan ";*/
	int a[1000],b[1000];
int mem [1000][1000];
	//memset (mem , -1, sizeof (mem ));
int max(int a, int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}
/*int lcs( int i, int j) {
	if (i == -1 || j == -1) {
		return 0;
	}
	if (mem[i][j] != -1) {
		return mem[i][j];
	}
	int res = 0;
		res = max(res , lcs (i, j - 1));
		res = max(res , lcs (i - 1, j));
	if (a[i] == b[j]) {
		res = max(res , 1 + lcs(i - 1, j - 1));
	}
	mem [i][j] = res;
	return res;
}
void clear(){
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			mem[i][j]=-1;
		}
	}
}*/
int lcs(int i,int j){
	int kq=0;
	for(int k1=0;k1<i;k1++){
		for(int k2=0;k2<j;k2++){
			if(a[k1]==b[k2]){
				kq++;
				break;
			}
		}
	}
	return kq;
}
main(){
	int T,n,m,kq[10];
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		//clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
			scanf("%d",&b[i]);
		}
	kq[t]=lcs(n,m);
	}
	for(int i=0;i<T;i++){
		printf("%d",kq[i]);
	}	
}
