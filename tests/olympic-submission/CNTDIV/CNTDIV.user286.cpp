#include<stdio.h>
#include<conio.h>
int main(){
	int m,n;
	printf("Dang ma tran ban muon nhap co so hang ");
	scanf("%d",&m);
	printf("\nDang ma tran ban muon nhap co so cot ");
	scanf("%d",&n);
	printf("Nhap ma tran ban muon nhap \n");
	int a[m][n];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	}
    printf("Ma tran a ban vua nhap la\n");
 	for(int i=1;i<=m;i++){
		for(int j=1;j<=
		n;j++)
		printf("%d-    ",a[i][j]);
		printf("\n");
}
}
