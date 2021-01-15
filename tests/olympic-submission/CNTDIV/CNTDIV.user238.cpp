#include <iostream>
#include <string.h>

using namespace std;

bool a[100000000];

int main()
{
    long q;
    long long t,t2;
    long n;
    cin>>q;
    for (long i=1;i<=q;i++)
    {
        memset(a,true,sizeof(a));
        long dem=0;
        cin>>n;
        t=n*(n+1)*(n+2);
        t2=t*t;
        for (long i=2;i<t;i++)
            if (t2%i==0 && t%i!=0) dem++;
        cout<<dem<<endl;
    }
    return 0;
}

