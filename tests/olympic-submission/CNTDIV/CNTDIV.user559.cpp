#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=1e6+5;
const int oo=1e9+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

int nq,uc[N+5];
vector<int> q;
void sang()
{
    for (int i=2;i<=N;i++) if (!uc[i])
    {
        uc[i]=i;
        for (int j=i;j<=N/i;j++) uc[i*j]=i;
    }
}
void phantich(int x)
{
    while (x>1)
    {
        int g=uc[x];
        while (x%g==0)
        {
            q.push_back(g);
            x/=g;
        }
    }
}
int main()
{
	//freopen("CNTDIV.inp","r",stdin);
	//freopen("CNTDIV.out","w",stdout);
	ios_base::sync_with_stdio(false);
    sang();
    cin>>nq;
    while (nq--)
    {
        int n;
        cin>>n;
        q.clear();
        phantich(n);
        phantich(n+1);
        phantich(n+2);
        sort(q.begin(),q.end());
        long long res1=1,res2=1;
        for (int i=0,j=0;i<q.size();i++)
        {
            long long dem=0;
            while (j<q.size() && q[j]==q[i]) {dem++; j++;}
            res1=res1*(dem+1);
            res2=res2*(dem*2+1);
            i=j-1;
        }
        cout<<(res2-1)/2-(res1-1)<<'\n';
    }
	return 0;
}
