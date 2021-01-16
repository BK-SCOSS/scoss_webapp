#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int exc(queue<int> &a, queue<int> &b)
{
    int time = 0;
    if ((a.size() == 1 && b.size() == 0) || (a.size() == 0 && b.size() == 1))
    {
        return 0;
    }
    while (a.size() > 0)
    {
        if (a.size() % 2 == 0)
        {
            int tmp = 0;
            tmp += a.front();
            a.pop();
            tmp += a.front();
            a.pop();
            b.push(tmp);
            if (time < tmp)
            {
                time = tmp;
            }
        }
        else
        {
            if (a.size() == 1)
            {
                int temp = a.front();
                a.pop();
                b.push(temp);
                break;
            }
            int tmp = 0;
            tmp += a.front();
            a.pop();
            tmp += a.front();
            a.pop();
            b.push(tmp);
            if (time < tmp)
            {
                time = tmp;
            }
        }
    }

    return time += exc(b, a);
}
int main()
{
    int T, n;
    int *total = new int[T];

    cin >> T;
    for (int l = 0; l < T; l++)
    {
        queue<int> a;
        queue<int> b;
        int time = 0;
        int k = 0;

        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cin >> k;
            a.push(k);
        }

        total[l] = exc(a, b);
    }
    for (int i = 0; i < T; ++i)
    {
        cout << total[i] << endl;
    }

    // system("pause");
    return 0;
}