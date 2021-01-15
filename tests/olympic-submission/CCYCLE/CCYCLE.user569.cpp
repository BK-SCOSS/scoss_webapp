#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define pob pop_back
const int N = 1e4+10, mod = 1e9+7;
int n,l,s,t;
vector<int> adj[N];
void add(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
ll dp[1001][1001];
int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> s >> t;
    for (int i = 1; i <= 3*n ; i+=3)
    {
        add(i,i+2);
        add(i,i+1);
        add(i+2,i+3);
    }
    add(1,3*n);
    for(auto v : adj[s]){
        dp[1][v] = 1;
    }
    for (int i = 2; i <= l; i++)
    {
        for (int j = 1; j <= 3*n; j++)
        {
            for(auto k : adj[j]){
                dp[i][k] += dp[i-1][j];
                dp[i][k] %= mod;
            }
        }
    }
    
    cout << dp[l][t] << endl;
    
    
    



    return 0;
}