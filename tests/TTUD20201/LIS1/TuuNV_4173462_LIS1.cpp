#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

int T;
int n;
long long a[MAX];
int mem[MAX];

int lis(int i)
{
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int result = 1;
    for (int j = 0; j < i; j++)
    {
        if (a[j] == (a[i] - 1))
        {
            result = max(result, 1 + lis(j));
        }
    }
    mem[i] = result;
    return result;
}
void run()
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < lis(i))
        {
            max = lis(i);
        }
    }
    cout << max << endl;
}
int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            mem[j] = -1;
        }
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        run();
    }
    return 0;
}
