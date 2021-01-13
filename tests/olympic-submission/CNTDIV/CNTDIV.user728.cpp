#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ull unsigned long long

int main()
{
    int q;
    cin >> q;
    int n, t, t2;
    for(int i = 0; i < q; ++i)
    {
        int ans = 0;
        cin >> n;
        t = n * (n + 1) * (n + 2);
        t2 = t * t;
        for(int i = 2; i < t; ++i)
        {
            if(t2 % i == 0 && t % i != 0) ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}

