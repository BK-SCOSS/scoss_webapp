#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


int main()
{
    long m,n,t,k;
    long a[100005];
    long long f[100005];

    long long kq,c;
    cin>>t;

    while (t>0)
    {
        t--;
        cin>>n; f[0]=0;
        for (int i=1; i<=n; i++) 
        {
            cin>>a[i];
            f[i]=f[i-1] + a[i];
        }
        
        k=2; kq=0;
        while (k<=n)
        {
            c=0;
            for (int i=1; i<=n/k; i++)
            {
                c=max(c,f[k*i] - f[k*(i-1)]);
            }
            
            kq=kq+c;
            k=k*2;
           
        }
        kq=kq+f[n];
        cout<<kq<<endl;
        
    }
  

}