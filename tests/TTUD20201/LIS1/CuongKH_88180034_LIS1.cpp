#include <iostream>
#include <algorithm>
using namespace std;
 
int main ()
{
	
    int n;
    cin>>n;
    long arr[1003];
    long F[1003];
    for (int i=1; i<=n; i++)
        cin>>arr[i];
    arr[0] = 0;
    F[0] = 0;
    for (int i=1; i<=n; i++)
    {
        F[i] = 1;
        for (int j=i-1; j>=1; j--)
        {
            if (arr[i]>arr[j])
            {
                F[i]=max(F[i], F[j]+1);
            }
        }
    }
    
    long dmax = 1;
    for (int i=1; i<=n; i++)
        if (F[i]>=dmax)
            dmax = F[i];
    cout<<dmax;
    return 0;
}
