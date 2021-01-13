#include <bits/stdc++.h>

using namespace std;
long long T,a[10000][10000];
int main()
{
    cin >> T;
    for (int i=0;i<T;++i)
    {
        for (int j=0;j<2;++j)
            cin >> a[i][j];
    }
    for (int i=0;i<T;++i)
    {
        unsigned long long s=0;
        for (int j=0;j<2;++j)
        {
            s+=a[i][j];
        }
        cout <<s<<endl;

    }
    return 0;
}
