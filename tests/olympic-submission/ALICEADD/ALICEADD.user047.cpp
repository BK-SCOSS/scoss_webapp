
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unsigned long long int a, b;
    while (n > 0) {
        cin >> a >> b;
        cout << a + b << "\n";
        n--;
    }
}