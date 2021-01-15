#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    unsigned long long a[T];
    unsigned long long b[T];
    unsigned long long c[T];
    if (T>10 || T<0) getchar();
    else
    {
        for (int i=0; i<T; i++)
        {
            scanf("%llu %llu", &a[i], &b[i]);
        }
        for (int i=0; i<T; i++)
        {
            c[i] = a[i] + b[i];
            printf("%llu", c[i]);
        }
        getchar();
    }
}
