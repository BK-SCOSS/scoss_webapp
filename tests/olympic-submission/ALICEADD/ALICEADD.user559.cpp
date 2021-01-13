#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=2e5;
const int oo=1e9+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

string cong(string a, string b)
{
    while (a.length()<b.length()) a="0"+a;
    while (a.length()>b.length()) b="0"+b;
    int nho=0;
    for (int i=a.length()-1;i>=0;i--)
    {
        int so=a[i]+b[i]-'0'*2+nho;
        a[i]=char(so%10+'0');
        nho=so/10;
    }
    if (nho) a="1"+a;
    return a;
}
int ntest;
int main()
{
	//freopen("ALICEADD.inp","r",stdin);
	//freopen("ALICEADD.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin>>ntest;
    while (ntest--)
    {
        string a,b;
        cin>>a>>b;
        cout<<cong(a,b)<<endl;
    }
	return 0;
}
