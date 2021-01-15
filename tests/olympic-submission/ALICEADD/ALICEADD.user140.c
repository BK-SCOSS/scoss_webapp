#include<stdio.h>
int main()
{
    int so_du_lieu,a[1000],b[1000],i;
    scanf("%d",&so_du_lieu);
    for(i=0;i<so_du_lieu;i++)
    {
        scanf("%d",&a[i]);printf(" ");
        scanf("%d",&b[i]);
    }
    for(i=0;i<so_du_lieu;i++)
    {
        printf("%d\n",a[i]+b[i]);
    }
}