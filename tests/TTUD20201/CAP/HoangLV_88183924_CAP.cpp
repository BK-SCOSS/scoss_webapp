#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

int a[101], b[N];
int n, m;

int check(int i){
    for(int j=0; j<i; j++){
        if(a[j] == a[i]) return 0;
    }
    return 1;
}

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];
}

void solve()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (check(i))
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i] == b[j])
                {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        input();
        solve();
    }
    return 0;
}
