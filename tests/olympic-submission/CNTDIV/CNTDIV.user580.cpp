#include <bits/stdc++.h>
using namespace std;
int check(unsigned long long n)
{
    unsigned long long t, p, d, m,count;
    t = n*(n+1)*(n+2);
    p = t*t;
    for(int i = 1; i<=p;i++)
    {
        d = p % i; 
        m = t % i;
        if(d != m && d < t)
            count++;
        return count;
    }
}
int main()
{
    unsigned long long n, q,t;
    cin >> q;
    for(int i = 0; i <q;i++)
    {
        cin >> n;
        cout << check(n);
    }
}