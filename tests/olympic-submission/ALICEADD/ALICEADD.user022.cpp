#include <iostream>

using namespace std;

int main()
{
    int n,i;
    do
    {
     cin>>n;
    }while(n>10||n<0);
    long long int a[n],b[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]+b[i]<<endl;
    }
    return 0;
}
