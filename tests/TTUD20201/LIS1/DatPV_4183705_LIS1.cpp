#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
 
struct pn
{
   long gt;
    long vt;    
};

pn a[1000007];
long n,t,k,m,kq,c,s;

pn tg;


bool SoSanh(const pn &x, const pn &y)
{
    return x.gt < y.gt;
}


int main()
{
    cin>>t;
    while (t>0)
    {
        t--;
        cin>>n;
    
        for (int i=1; i<=n; i++) 
        {
            cin>>a[i].gt;
            a[i].vt=i;
        }
        sort(a+1, a+n, SoSanh);
        a[0].gt=0;
        a[0].vt=0;
        m=0; kq=1; s=0; c=1000000;
        for (int i=1; i<=n; i++)
        if (a[i].gt==a[i-1].gt)
        {
           if (a[i].vt>s) c=min(c,a[i].vt);
        }
        else
        {
            k=0;
            if (a[i].gt==a[i-1].gt+1)
            if (a[i].vt>c)
            { m++; k=1; s=c;}
            if (k==0) { kq=max(kq,m); m=1; s=0;};
            c=a[i].vt;

        }
        kq=max(kq,m);
       
        cout<<kq<<endl;
    
    }
}