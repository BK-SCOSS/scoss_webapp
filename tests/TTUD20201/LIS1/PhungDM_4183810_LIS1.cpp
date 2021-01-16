#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int T ;
    cin >>T ;
    while (T>=1)
    {
       int n ;
       cin>>n ;
       int a[n] ;
       for (int k =0 ;k<n ;k++){
          cin >>a[k] ;
       }
       int f[n] ;
       f[0] =1;
        int result = 1;
        for (int i=1; i<n; i++)
        {
            f[i] = 1;
            for (int j=0; j<i; j++) if (a[j] ==(a[i]-1))
                {
                    f[i] = max(f[i], f[j] + 1);
                }
            result = max(result, f[i]);
        }
        cout<<result;
        T--;
    }

}

