#include <bits/stdc++.h>

using namespace std;

int n,k;
struct Data {
    int f;
    int s;
    int cost;
};
Data A[10007];
bool cpm(Data X, Data Y){
    return X.f < Y.f;
}
int f[10007][10007];
int slv(int i, int j){
    if (i == n+1) return 0;
    if (f[i][j] != -1) return f[i][j];
    int cur;
    if (A[j].s <= A[i].f) cur = max(slv(i+1,i) + A[i].cost,slv(i+1,j));
    else cur = slv(i+1,j);
    return f[i][j] = cur;
}
int main()
{
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin >> A[i].f >> A[i].s >> A[i].cost;
        A[i].s += A[i].f + k;

    }
    sort(A+1,A+n+1,cpm);
    memset(f,-1,sizeof(f));
    cout<<slv(0,0);
    return 0;
}
