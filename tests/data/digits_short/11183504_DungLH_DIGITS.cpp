#include <iostream>

using namespace std;

bool check(int a, int b)
{
    if (b / 10000 != (a / 10) % 10)
        return false;
    if (b % 10 != a % 10)
        return false;
    int x[4];
    x[0] = a / 1000;
    x[1] = (a / 100) % 10;
    x[2] = (a / 10) % 10;
    x[3] = a % 10;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
        {
            if (x[i] == x[j])
                return false;
        }
    int y[5];
    y[0] = b / 10000;
    y[1] = (b / 1000) % 10;
    y[2] = (b / 100) % 10;
    y[3] = (b / 10) % 10;
    y[4] = b % 10;
    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < 5; j++)
        {
            if (y[i] == y[j])
                return false;
        }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            if (x[i] == y[j])
                return false;
    return true;
}

int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int result = 0;
        for (int j = 1023; j <= 9876; j++)
        {
            if (check(j, x - j))
                result++;
            if (x - j < 10233)
                break;
        }
        cout << result << endl;
    }
    return 0;
}
