#include <iostream>

using namespace std;

int T;
unsigned long long a, b;

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;
        cout << a+b;
    }
    return 0;
}
