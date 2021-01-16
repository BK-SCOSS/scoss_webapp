#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    long m,n,kq,t,k,c;
    long a[1000];
    long b[1000];

    cin>>t;
    while (t>0)
    {
        t--; kq=0;
        cin>>n;
        for (int i=1; i<=n; i++) cin>>a[i];
        
        cin>>m;
        b[0]=0;
        for (int i=1; i<=m; i++)
        {
            cin>>b[i];
            
            for (int j=1; j<=n; j++)
            if (b[i]==a[j]) 
            { 
                kq++; 
                break; 
            }
        }

        cout<<kq<<endl;

    }
}