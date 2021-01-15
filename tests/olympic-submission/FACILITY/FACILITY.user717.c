#include<conio.h>
#include<stdio.h>
int main(){
    int T;
    int a[10][2];
    printf("Nhap so dong du lieu: ");
    scanf("%d",&T);
    printf("Nhap du lieu tung dong: \n");
    for(int i=0;i<T;i++){
        printf("nhap dong %d\n",i+1);
        printf("nhap so 1:  ");scanf("%d",&a[i][1]);
        printf("nhap so 2:  ");scanf("%d",&a[i][2]);
    }
    for(int i=0;i<T;i++){
        printf("Tong so keo la: \n");
        printf("%d\n",a[i][1]+a[i][2]);
    }
    }