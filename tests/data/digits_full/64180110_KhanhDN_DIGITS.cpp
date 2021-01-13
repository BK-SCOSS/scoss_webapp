#include <bits/stdc++.h>

using namespace std;

int T, N;
int chuso[8];
bool a[10];
int dapso, tong;

void _input()
{
    cin >> N;
    for (int i = 0; i <= 9; i++)
    {
        a[i] = true;
    }
    dapso = 0;
    tong = 0;
}

void _try(int k)
{
    if (k == 8)
    {
        tong = chuso[1] * 1000 + chuso[2] * 100 + chuso[3] * 10010 + chuso[4] * 2 + chuso[5] * 1000 + chuso[6] * 100 + chuso[7] * 10;
        if (tong == N)
        {
            for (int i = 1; i <= 7; i++)
            {
                //cout << chuso[i] << " ";
            }
            //cout << endl;
            dapso = dapso + 1;
        }
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (!a[i])
        {
            continue;
        }
        if ((i == 0) && ((k == 1) || (k == 3)))
        {
            continue;
        }

        chuso[k] = i;
        a[i] = false;
        _try(k + 1);
        a[i] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        _input();
        _try(1);
        //cout << N << endl;
        cout << dapso << endl;
    }
    return 0;
}