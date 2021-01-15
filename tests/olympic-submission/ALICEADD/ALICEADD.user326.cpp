#include <bits/stdc++.h>

using namespace std;
long long t ;
string a, b , ans ;
int main()
{
   // freopen("ALICEADD.inp","r",stdin);
   // freopen("ALICEADD.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>a>>b;
        ans = "";
      //  cout<<t<<" x "<< a<<" X "<< b <<endl;
        while ( a.length() > b.length() ) b = '0' + b;
        while ( a.length() < b.length() ) a = '0' + a;
      //  cout<<t<<" x "<< a<<" X "<< b <<endl;
        int nho = 0, tong = 0;
        for (int i=a.length()-1;i>=0;i--)
        {
            tong = a[i]-'0' + b[i] - '0' + nho;
            ans =  to_string(tong%10) + ans;
            nho = tong/10;
        }
        if (nho==1) ans = '1' + ans;
        cout<<ans<<"\n";
    }
    return 0;
}
