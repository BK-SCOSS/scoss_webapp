#include <iostream>

using namespace std;
int t, n;
int a[100010];
int l[100010];
int main()
{
    cin>>t;
    int i;
    while(t--)
    {
        cin>>n;
        for( i = 0; i<n; i++){
            cin>>a[i];
        }
        l[0] = 1;
        int lm;
        for( i=1; i<n ; ++i){
            lm=0;
            for( int j=0 ; j<i ; ++j){
                if( a[j] +1 == a[i] )
                    lm=max(lm,l[j]);
            }
        l[i] = lm+1;
        }
        int lmax=0;
        for( i = 0 ; i<n; i++){
            if( l[i] > lmax){
                lmax = l[i];
            }
        }
        cout<<lmax<<endl;
    }


    return 0;
}
