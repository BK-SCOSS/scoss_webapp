#include <bits/stdc++.h>
using namespace std;

void Process(int n)
{
    int d=0;
    long long s=1,sqr,i;
    for (int i=0;i<3;i++) s*=n+i;
    sqr=s*s;
    for (int i=2;i<s;i++)
    {
        if (s%i ){
            if (sqr % i==0) d++;
        }
    }
    cout <<d<<endl;
}
int main()
{
    int n,q,d;
    long long s=1,sqr,i;
    cin>>q;
    for (int i=0;i<q;i++)
    {
        cin>>n;
        Process(n);
    }
    return 0;
}


