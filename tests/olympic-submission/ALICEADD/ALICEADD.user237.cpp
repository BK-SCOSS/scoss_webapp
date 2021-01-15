#include<iostream>
using namespace std;
int main()
{
    int T ,a[100],b[100];
    cin>>T;
    cout<<"\n";
    for(int i = 0;i<T;i++)
    {
        cin>>a[i];
    }
    for(int i= 0;i<T;i++)
    {
        cin>>b[i];
    }
    for(int i =0;i<T;i++)
    {
        cout<<a[i]+b[i]<<"\n";
    }
    return 0;

}