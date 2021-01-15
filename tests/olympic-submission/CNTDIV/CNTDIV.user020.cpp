#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Q;
    cin>>Q;
    for(int i=1;i<=Q;i++)
    {
        int n;
        cin>>n;
        long long t=n*(n+1)*(n+2);
        int cnt=0;
        for(long long i=4;i<t;i++)
        {
            if(t*t%i==0 && t%i!=0)
            {
                //cout<<i<<" ";
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
