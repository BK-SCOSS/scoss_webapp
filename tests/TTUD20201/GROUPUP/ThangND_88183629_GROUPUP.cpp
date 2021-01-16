#include <bits/stdc++.h>
using namespace std;
int T;
int *a;
int n;
int glob = 0;
void solve()
{
    
    while (n > 1)
    {
        
        int local = INT_MIN;
        for (int i = 0; i < n; i = i + 2)
        {
            if (i + 1 < n)
            {
                a[i/2] = a[i] + a[i + 1];
                local = max(local, a[i/2]);
            }
            else
            {
                a[i/2] = a[i];
                local = max(local,a[i/2]);
            }
            
        }
        glob += local;
        
        if(n % 2 == 0 )
        {
            n = n/2;
        }
        else
        {
            n = n/2 + 1;
        }
        
            
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for(int t = 0 ; t < T ; t++)
    {
        cin >> n;
        a = new int[n];
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a[i];
        }
        solve();
        cout << glob << endl;
        glob = 0;
    }
    
    
}