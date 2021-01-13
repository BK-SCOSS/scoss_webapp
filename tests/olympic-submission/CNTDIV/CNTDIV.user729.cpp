#include <iostream>
#include <bits/stdc++.h>
#define forinc(i, a, b) for(int i =a,_b=b;i<=_b;i++)
#define fordec(i, a, b) for(int i =a,_b=b;i>=_b;i--)

using namespace std;

int main()
{
    int n;int  dem;
    int a[10000+6];
    cin >> n;
    forinc(i, 1, n)
    {
        cin >> a[i];
    }
    forinc(i, 1, n)
    {
        int t=a[i]*(a[i]+1)*(a[i]+2);
        dem=0;
        forinc(i, 1, t)
        {
            if (t*t % i == 0 && t % i != 0)
            {
                dem++;
            }
        }
    }
    cout << dem << endl;

    return 0;
}
