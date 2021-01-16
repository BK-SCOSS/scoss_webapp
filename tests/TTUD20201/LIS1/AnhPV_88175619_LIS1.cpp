#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 1000001;

int T, n, a[MAXN];

void nhap()
{
    cin >> T;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void check()
{
    int s = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < n;)
        {
            int c = a[j] - a[i];
            if(c == 1)
            {
                s++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
    }
    cout << s << endl;

}

int main()
{
    nhap();
    check();
    return 0;
}

