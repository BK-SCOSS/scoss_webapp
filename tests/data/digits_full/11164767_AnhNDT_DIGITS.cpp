#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define pob pop_back
int t,n;
int cnt[2000010];
vector<vector<int>> ans;
set<int> s;
void gen(set<int> s,vector<int> res){
    if(res.size() == 7){
        ans.push_back(res);
        return;
    }
    for(int u : s){
        auto v = res;
        auto x = s;
        x.erase(u);
        v.push_back(u);
        gen(x,v);
    }
}
void check(vector<int> res){
    if(res[0] ==0 || res[2] == 0) return;
    int n = 0;
    for(int i = 0; i<= 3;i++){
        n *= 10;
        n += res[i];
    }
    int m = 0;
    for(int i = 2; i < 7;i++){
        if(i == 3) continue;
        m *= 10;
        m += res[i];
    }
    m *= 10;
    m += res[3];
    cnt[n+m]++;
    
}
int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0;i < 10;i++) s.insert(i);
    vector<int> res;
    gen(s,res);
    for(auto v : ans){
        check(v);
    }

    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << cnt[n] << endl;

    }
    

    return 0;
}