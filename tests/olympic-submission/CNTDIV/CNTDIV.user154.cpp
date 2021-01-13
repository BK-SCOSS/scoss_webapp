#include<bits/stdc++.h>
using namespace std;
int sol(int t, int t_2)
{
    int sum = 0;
    for(int i = 2; i < t; i++)
    {
        if((t_2%i == 0) && (t%i!=0))
        {
            sum+=1;
        }
    }
    return sum;
}
int main()
{
    int q;
    cin>>q;
    int n;
    for (int i = 0; i < q; i++)
    {
        cin>>n;
        cout<<sol(n*(n+1)*(n+2), n*n*(n+1)*(n+1)*(n+2)*(n+2))<<"\n";
    }
    return 0;
}
