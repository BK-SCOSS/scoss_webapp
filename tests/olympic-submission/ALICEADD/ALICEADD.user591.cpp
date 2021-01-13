#include <bits/stdc++.h>
using namespace std;

int T;
unsigned long long a, b; 

void add(unsigned long long a, unsigned long long b)
{
    long long a1 = a/10;
    a = a%10;
    long long b1 = b/10;
    b = b%10;
    unsigned long long c = (a+b)/10;
    if (a1+b1+c !=0)
        printf("%llu%d\n", a1+b1+c, (a+b)%10);
    else printf("%d\n", (a+b)%10);
    return;
}
int main()
{
    scanf("%d", &T);
    for (int t=1; t<= T; ++t)
    {
        scanf("%llu%llu", &a, &b);
        add(a, b);
    }
}