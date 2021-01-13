#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    unsigned long long a[n],b[n];
    
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        cin>>b[i];
    }
    for (int i=1; i<=n; i++) cout<<a[i]+b[i]<<endl;
    return 0;
}
