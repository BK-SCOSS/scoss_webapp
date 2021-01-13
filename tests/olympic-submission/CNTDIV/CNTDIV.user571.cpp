#include<bits/stdc++.h>
using namespace std;

int n,q;
map<int,int> divisors;

void divisorOf(int n)
{    
    int i=2;
    while(n>1)
    {
       if(n%i==0)
       {
           n/=i;
           divisors[i]++;
       }
       else i++;
    }
}

int main()
{
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        map<int,int> a;
        cin>>n;
        divisorOf(n);
        divisorOf(n+1);
        divisorOf(n+2);
        int k1=1,k2=1;
        for (auto i:divisors)
        {
            k1*=(2*i.second+1);
            k2*=(i.second+1);
        }
        k1=k1- int(k1/2);
        cout<<k1-k2<<endl;
    }
    return 0;
}
