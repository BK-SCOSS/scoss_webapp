#include<iostream>
using namespace std;
int main()
{
    long long q,n[1000000],t[1000000],t2[1000000];
    int count=0;
    cin>>q;
    cout<<"\n";
    for(int i=0;i<q;i++)
    {
        cin>>n[i];
        t[i]=n[i]*(n[i]+1)*(n[i]+2);
        t2[i]=t[i]*t[i];
        cout<<"\n";
    }
    for(int i =0;i<q;i++)
    {
        for(int j = 1;j<t[i];j++)
        {
            if(t[i]%j!=0 && t2[i]%j==0) count++;
        }
    }
    cout<<count;
    return 0;


}