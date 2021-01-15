#include <iostream>
using namespace std;

int main()
{
    int n;
    unsigned long long int a, b, a0, a1, b0, b1, c0, c1;
    cin >> n;
    while (n--) {
    cin >> a >> b;
    int div = 10;
    a1 = a / div, a0 = a % div;
    b1 = b / div, b0 = b % div;
    c1 = a1 + b1 + (a0 + b0) / div, c0 = (a0 + b0) % div;
    if (c1 == 0)
    {
        cout << c0;
    }
    else
    {
        cout << c1 << c0;
    }
    }
    return 0;
}