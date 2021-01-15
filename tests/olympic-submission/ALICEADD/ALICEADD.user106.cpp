#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    string* result = new string[T];
    for (int i = 0; i < T; i ++) {
        unsigned long long a, b;
        int e, f;
        cin >> a >> b;
        if (a + b <= 10)
            result[i] = to_string(a + b);
        else {
            e = a % 10;
            f = b % 10;
            a = a / 10;
            b = b / 10;

            if (e + f > 10)
                result[i] = to_string(a + b + 1) + to_string((e + f) % 10);
            else
                result[i] = to_string(a + b) + to_string(e + f);
        }
    }
    for(int i = 0; i < T; i ++) {
        cout << result[i]<< endl;
    }

    return 0;

}