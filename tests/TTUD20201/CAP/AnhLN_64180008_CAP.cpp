#include <iostream>
#include <vector>
using namespace std;
// vector<int> a;
// vector<int>b;

// int * c = new int [n];

int main()
{
    int n, m;
    int *a = new int[n];
    int *b = new int[m];
    int T;
    cin >> T;
    int *c = new int[T];

    int k = 0;

    for (int l = 0; l < T; l++)
    {
        int count = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (a[i] == b[j])
                {
                    ++count;
                }
            }
        }
        c[l] = count;
    }
    for (int i = 0; i < T; ++i)
    {
        cout << c[i] << endl;
    }

    // system("pause");
    return 0;
}
