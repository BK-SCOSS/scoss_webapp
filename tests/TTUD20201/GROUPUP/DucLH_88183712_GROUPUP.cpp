#include <iostream>
using namespace std;
int a[100005] = {};
int T, n;
int res = 0;

void inp()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void proc()
{
    int check = n;
    while (check != 1)
    {
        int tongtime = 0;
        int i = 1;
        if (check % 2 == 0)
        {
            check /= 2;
            for (int j = 1; j <= check * 2; j = j + 2)
            {
                int k = a[j] + a[j + 1];
                a[i] = k;
                tongtime = max(tongtime, a[i]);
                i++;
            }
        }
        else
        {
            check = check / 2 + 1;
            for (int j = 1; j <= check * 2 - 1; j = j + 2)
            {
                if (j == check * 2 - 1)
                    a[i] = a[j];
                else
                    a[i] = a[j] + a[j + 1];
                tongtime = max(tongtime, a[i]);
                i++;
            }
        }
        res += tongtime;
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        inp();
        proc();
        cout << res << endl;
    }
}