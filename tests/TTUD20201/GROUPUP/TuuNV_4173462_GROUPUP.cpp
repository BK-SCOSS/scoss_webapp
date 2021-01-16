#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int T;
long n;
int a[MAX];
void run()
{
    long time = 0;
    int step = 1;
    while (step < n - 1)
    {
        for (int i = 0; i < n; i += step*2)
        {
            if (i + step < n)
            {
                a[i] += a[i + step];
            }
        }
        int max = 0;
        for (int i = 0; i < n; i += step)
        {
            if ((a[i] > max) && (i + step < n))
            {
                max = a[i];
            }
        }
        time += max;
        step = step * 2;
    }
    cout << time << endl;
}

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        run();
    }
    return 0;
}