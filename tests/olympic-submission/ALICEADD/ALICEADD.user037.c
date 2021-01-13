#include<stdio.h>

int main()
{
    int a=0, b=0, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n",a+b);
    }
    return 0;
}