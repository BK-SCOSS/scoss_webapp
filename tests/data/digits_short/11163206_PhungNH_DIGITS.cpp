#include <bits/stdc++.h>

using namespace std;

int n;
int T;
int stus[10];

bool ifDiff(int x, int y)
{
    memset(stus, 0, sizeof(stus));
    while (x > 0)
    {
        if (stus[x % 10] == 1) return false;
        stus[x % 10] = 1;
        x /= 10;
    }
    y /= 100;
    while (y > 0)
    {
        if (stus[y % 10] == 1) return false;
        stus[y % 10] = 1;
        y /= 10;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n > 999999)
        {
            cout << 0;
            return 0;
        }
        int temp = 0;
        for(int i = 10000; i <= min(n, 99999); i++)
        {
            int j = n - i;
        //    cout << to_string(j).length() << endl;
            if ((to_string(j).length() == 4) && (i % 10 == j % 10) && (i / 10000 == (j % 100) / 10) && ifDiff(i, j)) temp++;
        }
        cout << temp << endl;
    }
    return 0;
}