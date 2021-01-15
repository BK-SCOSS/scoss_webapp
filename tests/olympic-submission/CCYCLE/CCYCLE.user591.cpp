#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
int n, L, s, t;
//int f11[57][57][1007];

int f1(int s, int t, int L)
{
    // printf("%d %d %d\n", s, t, L);
    if (L<0) return 0;
    if (L==0) 
    {
        if (s==t) return 1;
        return 0;
    }
    int g;
    //if (g!=0) return g;
    if (s%3 == 2)
    { 
        g = f1(s-1, t, L-1)%M;
        return g;
    }
    if (t%3 == 2)
    { 
        g = f1(s, t, L-1)%M;
        return g;
    }
    if (s == 1)
    { 
        g = (f1(3*n, t, L-1) + f1(3, t, L-1) + f1(s, t, L-2)) % M;
        return g;
    } 
    if (s%3 == 1){ 
        g = (f1(s-1, t, L-1) + f1(s+2, t, L-1) + f1(s, t, L-2)) % M;
        return g;
    }
    if (s == 3*n)
    { 
        g = (f1(s-2, t, L-1) + f1(1, t, L-1)) % M;
        return g;
    }
    g = (f1(s-2, t, L-1) + f1(s+1, t, L-1)) % M;
    return g;
}


int main()
{
    scanf("%d%d%d%d", &n, &L, &s, &t);
    printf("%d", f1(s, t, L));
}