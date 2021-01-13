#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int nt(long N)
{
    int d=0;
    for(int i=2;i<N;i++)
    {
        if((N*N)%i==0&&(N%i)!=0) d++;
    }
    return d;
}
int main()
{
    long i,Q;
    long d[100000];
    long T[100000];
    long n[100000];
    cin >> Q;
    for(long i=1;i<=Q;i++)
    {
        cin >> n[i];
        T[i]=n[i]*(n[i]+1)*(n[i]+2);
        d[i]=nt(T[i]);
    }
    for(long i=1;i<=Q;i++)
    {
        cout << d[i] << endl;
    }
}
