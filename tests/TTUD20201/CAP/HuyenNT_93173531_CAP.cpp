#include<bits/stdc++.h>
using namespace std;
unsigned long long A[1000];
unsigned long long B[1000];
int main()
{
    int stc;
    cin>>stc;
    for(int tc=1;tc<= stc; tc++)
    {
        A[0] = -1;
        B[0] = -1;
        unsigned long long ans=0;
        unsigned long long n,m;
        cin>>n;
        for( unsigned long long i=1;i<=n;i++)
        {
            cin>>A[i];
        }
        sort(A+1,A+1+n);
        cin>>m;
        for(unsigned long long i=1;i<=m;i++)
        {
            cin>>B[i];
        }
        sort(B+1,B+1+m);
        for(unsigned long long i=1;i<=n;i++)
        {
            if(A[i]== A[i-1]) continue;
            for(unsigned long long j=1;j<=m;j++)
            {
                if(A[i] == B[j])
                {
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }

}
