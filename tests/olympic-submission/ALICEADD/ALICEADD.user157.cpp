#include <bits/stdc++.h>

int main()
{
    int t;
    scanf("%i", &t);
    while(t--)
    {
        unsigned long long a, b;
        scanf("%llu%llu", &a, &b);
        unsigned long long low, high;
        low = (a % 1000000) + (b % 1000000);
        high = (a / 1000000) + (b / 1000000) + low / 1000000;
        low %= 1000000;
        if(high == 0)
        {
            printf("%llu\n", low);
            continue;
        }
        
        printf("%llu%06llu\n", high, low);
    }
}