#include<iostream>
using namespace std;
int main()
{
    int n,d;
    unsigned long long s,k;
    cin>>n;
    int a[n];
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for (int i=1; i<=n; i++)
    {
        k=a[i]*(a[i]+1)*(a[i]+2);
        s=k*k;
        d=0;
        for (int j=1; j<k; j++)
        {
            if ((s%j==0)&&(k%j!=0)) {d++;}
        }
        cout<<d<<endl;
    }

    return 0;
}
