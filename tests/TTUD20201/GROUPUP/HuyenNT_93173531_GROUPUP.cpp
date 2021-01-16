#include<bits/stdc++.h>
using namespace std;
int A[100011];
int main()
{
    int stc;
    cin>>stc;
    for(int tc=1; tc<=stc;tc++)
    {
        int n;
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>A[i];
        }
        while(n>1)
        {
            for(int i=1;i<=n;i+= 2)
            {
                A[i] += A[i+1];
                A[i+1] = 0;
            }
            int tmp=0;
            int tmax=0;
            for(int i=1;i<=n;i++)
            {
                if(A[i] > 0)
                    A[++tmp] = A[i];
                if(A[i] > tmax) tmax=A[i];
            }
            ans+= tmax;
            n=tmp;
        }
        cout<<ans<<endl;
    }
}
