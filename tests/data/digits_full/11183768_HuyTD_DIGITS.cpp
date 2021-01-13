#include <bits/stdc++.h>

using namespace std;
int T;
vector<int> N;
void input()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int tmp;
        cin >> tmp;
        N.push_back(tmp);
    }
}
int check(int i, int k, int ass[])
{
    if (ass[i] == 1)
        return 0;
    if ((k == 1 || k == 3) and i == 0)
        return 0;
    return 1;
}
int cal(int a[])
{
    return a[1] * 1000 + a[2] * 100 + a[3] * 10 + a[4] + a[3] * 10000 + a[5] * 1000 + a[6] * 100 + a[7] * 10 + a[4];
}
int TRY(int k, int ass[], int a[], int &ans, int t)
{
    for (int i = 0; i <= 9; i++)
    {
        if (check(i, k, ass))
        {
           a[k] = i;
            ass[i] = 1;
            if (k == 7)
            {
                if (cal(a) == t)
                    ans++;
            }
            else
                TRY(k + 1, ass, a, ans, t);
            ass[i] = 0;
        }
    }
}
int main()
{
    input();
    for (auto t : N)
    {
        int a[8] = {0};
        int assigned[10] = {0};
        int ans = 0;
        TRY(1, assigned, a, ans, t);
        cout << ans << endl;
    }
}