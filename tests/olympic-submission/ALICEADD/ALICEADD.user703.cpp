#include <iostream>
using namespace std;
int main()
{
    unsigned long long a, b, a0, b0, a1, b1, t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        a0 = a / 10;
        a1 = a % 10;
        b0 = b / 10;
        b1 = b % 10;
        if (a1 + b1 >= 10)
            cout << a0 + b0 + 1;
        if (a0 + b0 > 0)
            cout << a0 + b0;
        cout << (a1 + b1) % 10 << endl;
    }
}