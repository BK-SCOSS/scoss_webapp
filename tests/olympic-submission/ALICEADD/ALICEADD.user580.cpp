#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,a[t],b[t],c[t];
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        cin >> a[i];
        cin >> b[i];
        c[i] = a[i] + b[i];
        cout << c[i];
    }
}