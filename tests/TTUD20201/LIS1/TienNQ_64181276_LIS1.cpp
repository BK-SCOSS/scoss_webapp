#include <iostream>
#include <list>

using namespace std;

int mai()
{
    int count = 0;
    int n;
    cin >> n;
    int *a;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    int *b;
    b = new int[m];

    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
    }
    list<int> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] != a[j])
            {
                l.push_back(a[i]);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (b[i] == l.front())
        {
            count = count + 1;
            l.pop_front();
        }
    }
cout << count << endl;
    delete[] a;
    delete[] b;

    return 0;
}