#include <iostream>

using namespace std;

int T;
int n;

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        long long a = n * (n + 1) * (n + 2);
        long long b = a * a;
        int r = 0;
        for (int j = 4; j < a; j++)
            if (b % j == 0 && a % j != 0) r++;
        cout << r;
    }
    return 0;
}
