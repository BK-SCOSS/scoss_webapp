#include <stdio.h>


int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        long long int a, b;
        scanf("%lld", &a);
        scanf("%lld", &b);
        printf("%llu\n", a + b);
    }
    return 0;
}
