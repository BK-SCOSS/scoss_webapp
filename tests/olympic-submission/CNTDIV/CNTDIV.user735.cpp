#include <iostream>
#include <math.h>


using namespace std;

int souoc(long long n)
{
    long long d=0;
    for(long long i=1;i<=sqrt(n);i++)
    {
      if( n % i==0 && i*i<n) d=d+2;
      if( n % i==0 && i*i==n) d=d+1;
    }
    return d;
}

int main()
{
    long long n,kq=0,tru=0;
    long long q;
   
    cin>>q;
    for(long long i=0;i<q;i++)
    {
        cin>>n;
        if (n%2==1)
        {
            tru=souoc(n*n)*souoc((n+1)*(n+1))*souoc((n+2)*(n+2));
            kq=souoc(n)*souoc(n+1)*souoc(n+2);
        }
        else if(n%2==0)
        {
            if((n/2)%2==0)
            {
            tru=souoc(n*n*4)*souoc((n+1)*(n+1))*souoc((n+2)*(n+2)/4);
            kq=souoc(2*n)*souoc(n+1)*souoc(n/2+1);
            }
            else if((n/2)%2==1)
            {
            tru=souoc(n*n/4)*souoc((n+1)*(n+1))*souoc((n+2)*(n+2)*4);
            kq=souoc(n/2)*souoc(n+1)*souoc(n*2+4);
            }
            
        }
        cout<<(tru-1)/2-kq+1<<endl;
    }
    system("pause");
}