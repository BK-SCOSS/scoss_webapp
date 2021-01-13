#include<bits/stdc++.h>
using namespace std;
const int N=3e4+2,M=1e9+7;
int n,L,s,t,dp[N][1002];
bool ok[N][1002];
vector<int> adj[N];
void add(int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}
queue<pair<int,int>> Q;
int main(){
    cin >> n >> L >> s >> t;
    for(int i=1; i<n; ++i){
        add(3*i+1,3*i);
        add(3*i+1,3*i+2);
        add(3*i+1,3*i+3);
    }
    add(1,3*n);
    add(1,2);
    add(1,3);
    dp[s][0]=1;
    Q.push(make_pair(s,0));
    while (!Q.empty()){
        pair<int,int> u=Q.front(); Q.pop();
        if (u.second==L) break;
        for(auto x:adj[u.first]){
            dp[x][u.second+1]+=dp[u.first][u.second];
            dp[x][u.second+1]%=M;
            if (ok[x][u.second+1]) continue;
            ok[x][u.second+1]=true;
            Q.push(make_pair(x,u.second+1));
        }
    }
    cout << dp[t][L];
    return 0;
}
