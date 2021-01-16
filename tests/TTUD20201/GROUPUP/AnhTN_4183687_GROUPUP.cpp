#include <bits/stdc++.h>
using namespace std;
int T;
long long n, a[100000000];
long long b[10000000];
long long tongthoigian=0;
long long counts[10000000];
long long sonhom;
void input()
{
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sonhom=n;
}
void solve(long long n)
{
    long long thoigian = 0;
    while (sonhom != 1)
    {
        if (sonhom % 2 == 0)
        {
            for (long long i = 1; i <= sonhom / 2; i++)
            {
                a[i] = a[2 * i - 1] + a[2 * i];
                thoigian = max(thoigian, a[i]);
            }

            tongthoigian+=thoigian;
            sonhom=sonhom/2;
            solve(sonhom);
        }

        if (n % 2 == 1)
        {
            for (long long i = 1; i <= n / 2; i++)
            {
                a[i] = a[2 * i - 1] + a[2 * i];
                thoigian = max(thoigian, a[i]);
            }
            a[n / 2 + 1] = a[n];
            tongthoigian+=thoigian;
            sonhom=sonhom/2+1;
            solve(sonhom);
        }
    }
}
int main(){
    cin>>T;
    for(long long i=1;i<=T;i++){
    input();
    
    solve(n);
    counts[i]=tongthoigian;
    }
    for(long long i=1;i<=T;i++)
        cout<<counts[i]<<" "<<endl;
}