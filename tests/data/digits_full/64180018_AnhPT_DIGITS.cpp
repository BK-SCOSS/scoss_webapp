#include <bits/stdc++.h>
using namespace std;
int a[8], N;
int ans = 0;
//a[1] = H;a[2]=U,a[3]=S,a[4]=T,a[5]=O,a[6]=I,a[7]=C,
int fun()
{
    return 1000 * a[1] + 100 * a[2] + 10 * a[3] + a[4] 
    + 10000 * a[3] + 1000 * a[5] + 100 * a[6] + 10 * a[7] + a[4];
}
bool check(int k)
{
    for (int j = 0; j < k; j++)
    {
        if (a[k] == a[j])
            return false;
    }
    return true;
}
void TRY(int k)
{
    if (k == 8)
    {
        if ((a[1] != 0) && (a[3] != 0))
        {
            if (fun() == N)
                ans++;
        }
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            a[k] = i;
            if (!check(k))
                continue;
            TRY(k + 1);
            a[k] = 0;
        }
    }
}
int main()
{
    int T;
    cin >> T;
    a[0]=-1;
    while (T > 0)
    {
        ans = 0;
        cin >> N;
        TRY(1);
        cout << ans;
        cout << endl;
        T--;
    }
}