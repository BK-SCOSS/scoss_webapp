#include <bits/stdc++.h>

using namespace std;

struct node{
    int idx;
    int val;
};
vector<int> edge[200001];
node a[200001];
int dp[200001];
int n,res;

bool cmp(node a, node b){
    return a.val < b.val;
}
void addedge(int u, int v){
    edge[u].push_back(v);
}
int f(int u){
    if(dp[u]!=-1) return dp[u];
    int res=1;
    for(int i = 0; i<= (int)edge[u].size()-1;i++){
        int v = edge[u][i];
        res= max(res,f(v)+1);
    }
    return res;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--){
        for(int i = 1 ; i <= 100000; i++){
            dp[i]= -1;
            edge[i].clear();
        }
        res= 0;
        scanf("%d",&n);
        for(int i = 1; i <=n; i++){
            scanf("%d",&a[i].val);
            a[i].idx=i;
        }
        sort(a+1,a+n,cmp);
        for(int i = 1; i <= n -1 ; i++){
            if(a[i].val+1==a[i+1].val){
                addedge(a[i].idx,a[i+1].idx);
            }
        }
        for(int i = 1; i <=n; i++){
            res= max(res,f(i));
        }
        cout << res;
        }
        return 0;
    }
