#include <bits/stdc++.h>
using namespace std;

int a[100001], n, ans = 0;

void f(int arrCnt, int arr[])
{
    if (arrCnt == 1)
        return;
    if (arrCnt % 2 == 1)
    {
        int cnt = arrCnt / 2 + 1, res = 0;
        int arr2[cnt];
        arr2[cnt - 1] = arr[arrCnt - 1];
        for (int i = 0; i < cnt - 1; i++)
        {
            arr2[i] = arr[2 * i] + arr[2 * i + 1];
            res = max(res, arr2[i]);
        }
        ans += res;
        f(cnt, arr2);
    }
    else
    {
        int cnt = arrCnt / 2, res = 0;
        int arr2[cnt];
        for (int i = 0; i < cnt; i++)
        {
            arr2[i] = arr[2 * i] + arr[2 * i + 1];
            res = max(res, arr2[i]);
        }
        ans += res;
        f(cnt, arr2);
    }
}

int main()
{
    // freopen("../../exam3/VD5/GROUPUP.inp", "r", stdin);
    int T;
    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        f(n, a);
        cout << ans << endl;
    }

    return 0;
}