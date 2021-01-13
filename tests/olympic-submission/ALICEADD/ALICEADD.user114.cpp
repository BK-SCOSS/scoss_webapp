#include<iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        unsigned long long A, B, a1, b1, a2, b2, c1, c2, C;
        cin >> A >> B;

        a1 = A/10;
        a2 = A - a1*10;
        b1 = B/10;
        b2 = B - b1*10;

        c1 = (a2+b2)/10;
        c2 = (a2+b2)%10;

        C = a1+b1+c1;
        if (C < 10)
            cout << c2 << endl;
        else
            cout << C << c2 << endl;
    }

    return 0;
}
