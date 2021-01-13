#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int a, b;

        cin >> a;
        cin >> b;

        cout << a+b << endl;
    }

    return 0;    
}