#include <iostream>
#include <stdio.h>

using namespace std;
int timuoc(long TT)
{
    long temp = TT*TT,dem=0, du1, du2;
    long j;
    for(j=2;j<TT;j++)
    {
        du1 = temp%j;
        du2 = TT%j;
        if((du1==0)&&(du2!=0)) dem++;
    }
    return dem;
}
int main()
{
    int Q, N,i=0;
    long T;
    cin>>Q;
    for(i=0;i<Q;i++)
    {
        cin>>N;
        T=N*(N+1)*(N+2);
        cout<<timuoc(T)<<endl;
    }
    return 0;
}

