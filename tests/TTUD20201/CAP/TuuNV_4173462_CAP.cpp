#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int T;
int n, m;
long long a[MAX], b[MAX];

void run()
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                result++;
            }
        }
    }
    cout << result << endl;
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
        cin >> m;
        for (int k = 0; k < m; k++)
        {
            cin >> b[k];
        }
        run();
    }

    return 0;
}