#include <iostream>
using namespace std;
int n = 0, T = 0;
int a[10], b[7];
int dem = 0;

int check(int k)
{
    int sum = 0;
    if (k == -1)
        return 0;
    if (k == 0)
        sum = 10010 * b[k];
    if (k == 1)
        sum = 10010 * b[0] + 1000 * b[1];
    if (k == 2)
        sum = 10010 * b[0] + 1000 * (b[1] + b[2]);
    if (k == 3)
        sum = 10010 * b[0] + 1000 * (b[1] + b[2]) + 100 * b[3];
    if (k == 4)
        sum = 10010 * b[0] + 1000 * (b[1] + b[2]) + 100 * (b[3] + b[4]);
    if (k == 5)
        sum = 10010 * b[0] + 1000 * (b[1] + b[2]) + 100 * (b[3] + b[4]) + 10 * b[5];
    if (k == 6)
        sum = 10010 * b[0] + 1000 * (b[1] + b[2]) + 100 * (b[3] + b[4]) + 10 * b[5] + 2 * b[6];
    return sum;
}

void TRY(int k)
{
    for (int v = 0; v < 10; v++)
    {
        if (a[v] == 0 && check(k - 1) <= n)
        {
            b[k] = v;
            a[v] = 1;
            if (k == 6)
            {
                if (check(k) == n && b[0] != 0 && b[1] != 0)
                {
                    dem++;
                }
            }
            else
            {
                TRY(k + 1);
            }
            a[v] = 0;
        }
    }
}

int main()
{
    cin >> T;
    for (int i = 0; i < 10; i++)
    {
        a[i] = 0;
    }

    for (int i = 0; i < T; i++)
    {
        cin >> n;
        TRY(0);
        cout << dem << "\n";
        dem = 0;
        b[7] = {};
        for (int j = 0; j < 10; j++)
        {
            a[j] = 0;
        }
    }
}