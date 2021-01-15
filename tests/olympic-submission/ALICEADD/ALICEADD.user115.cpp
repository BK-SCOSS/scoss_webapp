#include <iostream>
#include <vector>
using namespace std;

int main()
{
    unsigned int n, a1, b1;
    cin >> n;
    unsigned long long a, b, q[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> q[i][0] >> q[i][1];
    }

    for (int i = 0; i < n; i++)
    {
        a = q[i][0];
        b = q[i][1];
        if (a + b < 10)
            cout << a + b;
        else
        {
            a1 = a % 10;
            b1 = b % 10;
            a = a / 10;
            b = b / 10;
            if (a1 + b1 > 10)
                cout << a + b + 1 << (a1 + b1) % 10;
            else
                cout << a + b << a1 + b1 << endl;
        }
    }
    system("pause");
    return EXIT_SUCCESS;
}
