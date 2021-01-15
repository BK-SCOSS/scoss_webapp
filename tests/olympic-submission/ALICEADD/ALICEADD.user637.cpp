#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define bit(i,j) ((i>>j)&1)
using namespace std;
//---------------------------------------
void read(){}
template<class T, class ...V> void read(T &x,V& ...y)
{
    x=0;
    char c=getchar();
    int ok=(c=='-');
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-48, c=getchar();
    if(ok) x=-x;
    read(y...);
}
template<class T>void write(T x)
{
    if(x<0) putchar('-'), x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
template<typename T,typename V> T max(T& a,V& b){return (a>b)?a:b;}
template<typename T,typename ...V> T max(T& a, V&... b){return max(a,max(b...));}

template<typename T,typename V> T min(T& a,V& b){return (a>b)?b:a;}
template<typename T,typename ...V> T min(T& a, V&... b){return min(a,min(b...));}
//-----------------------------------------------
string operator+(string a,string b)
{
    while(a.size()<b.size())
        a='0'+a;
    while(a.size()>b.size())
        b='0'+b;
    int n=a.size();
    string res="";
    int carry=0;
    for(int i=n-1;i>=0;i--)
    {
        int tmp=a[i]+b[i]-96;
        tmp+=carry;
        carry=tmp/10;
        res=(char)(tmp%10+48)+res;
    }
    if(carry)res="1"+res;
    return res;
}
main()
{
    //#ifndef ONLINE_JUDGE
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    //#endif // ONLINE_JUDGE
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        cout<<a+b<<'\n';
    }
}
