#include <iostream>
#include <algorithm>

struct data
{
    long a,b,c,d;
    //a start b time c cost d finish
};

data s[1000000];
long d[10000];

using namespace std;

bool compare(data a1,data a2)
{
    return(a1.d < a2.d);
}

int main()
{
    long n,k;
    cin>>n>>k;
    for (long i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].b>>s[i].c;
        s[i].d=s[i].a+s[i].b+k;
    }

    sort(s+1,s+1+n,compare);
    d[1]=s[1].c;
    long cp=1;
    for (long i=1;i<n;i++)
    {
        if (s[cp].d>s[i+1].a)
        {
            if (d[i] > s[i+1].c) d[i+1]=d[i];
            else
            {
                d[i+1]=s[i+1].c;
                cp=i+1;
            }
        }
        else
        {
            d[i+1]=d[i]+s[i+1].c;
            cp=i+1;
        }
    }

    //for (long i=1;i<n;i++) cout<<d[i]<<" ";
    cout<<d[n];

    return 0;
}
