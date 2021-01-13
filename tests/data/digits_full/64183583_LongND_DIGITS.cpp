#include <bits/stdc++.h>

using namespace std;
int n;
int check[10];
int coso[10];
// so j cho vi tri k
int dem;
bool UCV(int j, int k)
{
    if (k == 1 || k == 3)
    {
        if (j == 0)
            return false;
    }
    return (check[j] == 0);
}
int tong;
void Try(int k)
{
    int j;
    int tmp;
    for (int j = 0; j <= 9; j++)
    {
        if (UCV(j, k))
        {
            tmp = tong;
            check[j] = 1;
            tong = tong + j * coso[k];
            if (k == 7)
            {
                if (tong == n)
                {
                    dem++;
                }
            }
            else
            {
                Try(k + 1);
            }
            tong = tong - j * coso[k];
            check[j] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    coso[1] = 1000;
    coso[2] = 100;
    coso[3] = 10010;
    coso[4] = 2;
    coso[5] = 1000;
    coso[6] = 100;
    coso[7] = 10;
    while(t--) {
        cin >>n;
        dem = 0;
        Try(1);
        cout << dem << endl;

    }

    // cout << UCV(1,1);

    return 0;
}