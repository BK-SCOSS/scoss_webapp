#include <bits/stdc++.h>
#define x first
#define y second
#define HANH "CNTDIV"
#define N 1000015
using namespace std;

int t, n, snt[N], d[N];
vector <int> f[N];
queue <int> q;

void cb()
{
    for(int i=2; i<=1202; ++i){
        if(snt[i]!=0) continue;
        int j=1;
        while(j*i<=1000010){
            snt[i*j]=1;
            f[i*j].push_back(i);
            ++j;
        }
    }
}

void dem(int n)
{
    int k=n;
    for(int i=0; i<f[n].size(); ++i){
        int u=f[n][i];
        //cout <<u <<endl;
        if(d[u]==0) q.push(u);
        while(k%u==0){
            ++d[u];
            k/=u;
        }
    }
    if(k!=1){
            if(d[k]==0) q.push(k);
        ++d[k];
    }
}

int main()
{
    cb();
    scanf("%d", &t);
    for(int i=1; i<=t; ++i){
        scanf("%d", &n);
        dem(n); dem(n+1); dem(n+2);
        int kq1=1, kq2=1;
        while(q.size()!=0){
            int u=q.front(); q.pop();
            //cout <<u <<" " <<d[u] <<endl;
            kq1=kq1*(2*d[u]+1);
            kq2=kq2*(d[u]+1);
            d[u]=0;
        }
        printf("%d\n", (kq1-1)/2-kq2+1);
    }
    return 0;
}
//1 2 3  4  5  6  7  8  9  10
//1 3 11 16 25 21 29 38 44 63
