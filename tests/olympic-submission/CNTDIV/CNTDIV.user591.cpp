#include <bits/stdc++.h>
#define N 1000007
using namespace std;

int T, n;
int isPrime[1000007];
int kprime = 0;
int prime[1000007];
void sangnt()
{
    for (int i = 2; i <= N; ++i)
        isPrime[i] = true;
    for (int i = 2; i*i <= N; ++i)
        if (isPrime[i])
        {
            for (int j = 2; i*j <= N; ++j)
                isPrime[i*j] = false;
        }
    for (int i=2; i <= N; ++i)
    {
        if (isPrime[i])
        {
            prime[++kprime] = i;
        }
    }
}
void process(int x)
{
    int j = 0;
    int x1 = x;
    vector <pair <int,int> > divisor;
    for (int i = 1; prime[i]*prime[i] <= (x); ++i)
    {
        if (x%prime[i] == 0)
        {
//            cout << prime[i];
            divisor.push_back(make_pair(prime[i], 0));
            while (x%prime[i] == 0)
            {
                divisor.back().second++;
                x=x/prime[i];
            }
        }
    }
//    cout << 0;
    if (x > 1) divisor.push_back(make_pair(x, 1));
    x = x1 + 1;
    for (int i = 1; prime[i]*prime[i] <= (x); ++i)
    {
        if (x%prime[i] == 0)
        {
            divisor.push_back(make_pair(prime[i], 0));
            while (x%prime[i] == 0)
            {
                divisor.back().second++;
                x=x/prime[i];
            }
        }

    }
    if (x > 1) divisor.push_back(make_pair(x, 1));
    x = x1 + 2;
    for (int i = 2; prime[i]*prime[i] <= (x); ++i)
    {
        if (x%prime[i] == 0)
        {
            divisor.push_back(make_pair(prime[i], 0));
            while (x%prime[i] == 0)
            {
                divisor.back().second++;
                x=x/prime[i];
            }
        }

    }
    if ((x)%2 == 0)
    {
        while (x%2==0)
        {
            x/=2;
            divisor.front().second++;
        }
    }
    if (x > 1) divisor.push_back(make_pair(x, 1));
    int u1 = 1;
    int u2 = 1;
    for (int i=0; i<divisor.size(); ++i)
    {
        // printf("%d %d\n", divisor[i].first, divisor[i].second);
        u1 *= (divisor[i].second+1);
        u2 *= (divisor[i].second * 2 + 1);
    }
    printf("%d\n", (u2/2) - (u1 - 1));
}
int main()
{
    sangnt();
    scanf("%d", &T);
//    for (int i=1; i <= 10; ++i)
//        cout << prime[i];
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d", &n);
        // printf("1\n");
        process(n);
    }
}
