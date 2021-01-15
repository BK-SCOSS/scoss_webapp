#include<bits/stdc++.h>
using namespace std;
long long t;
string a,b;
string congxau(string a,string b)
{
    //int n1 = a.length();
    //int n2 = b.length();
    while(a.length()<b.length()) a.insert(0,1,'0');
    while(a.length()>b.length()) b.insert(0,1,'0');
    int n= a.length();
  //   cout<<a <<' '<<b<<'\n';
    string c = a;
    int nho = 0;
    int tong;
    for(int i=n-1;i>=0;i--)
    {

        tong = (a[i] -48) + (b[i] - 48) +nho;
        if(tong > 9)
        {
            tong = tong -10;
            nho = 1;
        }else nho = 0;
        c[i] = tong +48;

    }
    if(nho == 1) c.insert(0,1,'1');
    return c;
}
int main(){
  // freopen("alice.inp","r",stdin);
  //  freopen("alice.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
    //    cout<<a <<' '<<b<<'\n';
        cout<<congxau(a,b)<<'\n';


    }
}
