#include <bits/stdc++.h>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define ll long long

using namespace std;

unsigned long long a, b, c, tg = 1e19+1e18, tg2 = 1e18, M = 1e19;
int t;

int main()
{
    scanf("%d", &t);
    fti(i, 1, t) {
        scanf("%llu %llu", &a, &b);
        if(a == M && b == M) printf("20000000000000000000\n");
        else
            if(tg - a <= b) {
                b = b - (tg - a) + tg2;
                printf("1%llu\n", b);
            }
            else printf("%llu\n", a + b);
    }
}
