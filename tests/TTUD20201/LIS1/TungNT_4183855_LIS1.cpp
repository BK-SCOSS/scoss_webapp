#include <bits/stdc++.h>
using namespace std;

int T, n;
int a[100000];
int f_max = -9999;

void init()
{
    cin >>n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
}

void TRY(int k)
{
    vector <int> v;
    int f;
    v.push_back(a[k]);
    for(int i=k+1; i<n; i++)
    {
        if(a[i] == (v.back()+1))
        {
            v.push_back(a[i]);
        }
    }
    f = v.size();
    if (f > f_max)
    {
        f_max = f;
    }
}

int main()
{
    cin >> T;
    for (int i=1; i<=T; i++)
    {
        init();
        for (int k=0; k<n; k++)
        {
            int f;
            if (a[k] >= a[0])
                TRY(k);
        }
        cout << f_max << endl;
        f_max = -9999;
    }
}
