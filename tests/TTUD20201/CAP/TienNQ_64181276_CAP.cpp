#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
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
        delete[] a;
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
        int len = l.size();
        int list<int> k;
        while (len > 0)
        {
            for (int i = 0; i < m; i++)
            {
                if (b[i] == l.front() )
                {
                    k.push_back(b[i]);
                }
            }
            len = len -1;
            l.pop_front();
        }
cout << k.size() << endl;
        delete[] b;
       
    }
    return 0;
}