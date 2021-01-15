#include <iostream>
using namespace std;

int main()
{
    unsigned long long Q, N, T, T2, count;
    cin >> Q;
    while (Q--)
    {
        cin >> N;
        T = N * (N + 1) * (N + 2);
        T2 = T * T;
        count = 0;
        for (unsigned long long i = 1; i < T; i++)
        {
            if (T % i != 0 && T2 % i == 0)
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}