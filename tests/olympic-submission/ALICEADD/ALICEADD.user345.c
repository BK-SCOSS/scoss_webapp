#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    while(n <= 0 || n > 10)
    {
        scanf("%d",&n);
    }
    int sum[n];
    int a = 0,b= 0;
    for(int i = 0;i < n;i++)
    {
        sum[i]= 0;
        scanf("%d",&a);
        scanf("%d",&b);
        sum[i] = a+b;
    }
    for(int i = 0;i<n;i++)
    {
        printf("%d\n",sum[i]);
    }
}