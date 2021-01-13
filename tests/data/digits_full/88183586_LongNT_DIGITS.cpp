#include <bits/stdc++.h>
using namespace std;


int T;
int para[] = {0, 10010, 1000, 1000, 100, 100, 10, 2};
int n;
int temp = 0;
int res = 0;
bool taken[10];
int a[10];
void clearall()
{
    for (int i = 1; i <= 7; ++i)
        a[i] = 0;
    for (int i = 0; i <= 9; ++i)
        taken[i] = 0;
    res = 0;
    temp = 0;
}
bool check(int i, int j)
{
    if (taken[j]) return false;
    if (temp + j*para[i] > n) return false;
    if (i == 1 && j == 0) return false;
    if (i == 3 && j == 0) return false;
    return true;
}
void confirm(int i, int j)
{
    a[i] = j;
    temp += j*para[i];
    taken[j] = true;
}
void unconfirm(int i, int j)
{
    temp -= j*para[i];
    taken[j] = false;
}
void out()
{
    if (temp == n)
    {
        // printf("%d%d%d%d %d%d%d%d%d", a[3], a[5], a[1], a[7], a[1], a[2], a[4], a[6], a[7]);
        // printf("\n%d\n", temp);
        res ++;
    }
}
void sinh(int i)
{
    if (i > 7)
    {
        out();
        return;
    }
    for (int j = 0; j < 10; ++j)
        if (check(i, j))
        {
            confirm(i, j);
            sinh(i + 1);
            unconfirm(i, j);
        }
}
void process(int n)
{
    sinh(1);
    printf("%d\n", res);
}

int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        clearall();
        scanf("%d", &n);
        process(n);
    }
}