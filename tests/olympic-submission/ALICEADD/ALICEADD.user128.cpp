#include <iostream>

using namespace std;

int main()
{
    int T, i;
    cin >> T;
    int a[T*2];
    for (i = 0; i < T; i++) {
        cin >> a[2*i] >> a[2*i+1];
    }
    for (i = 0; i < T; i++) {
        cout << (a[2*i] + a[2*i+1]) << endl;
    }
    return 0;
}




