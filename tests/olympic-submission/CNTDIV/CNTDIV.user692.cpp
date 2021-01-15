#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
int dem;
int tinh(long long x)
{
    dem = 0;
    long long tt = x*x;
    for(int i = 2; i <= x; i++)
        if ((x % i != 0) && (tt % i == 0)) dem++;
}
int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        long long n;
        cin >> n;
        long long k = n*(n+1)*(n+2);
        tinh(k);
        cout << dem;
    }
    return 0;
}
