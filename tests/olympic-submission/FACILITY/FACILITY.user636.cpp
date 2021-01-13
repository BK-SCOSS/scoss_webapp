#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int N = 1e6 + 3;

int n, k, l[N], r[N], ll[N], rr[N], ccost[N], cost[N], position;
long long res = 0, f[N], fen[2 * N];
vector<ii> customer;
int formTime(){
    for(int i = 1; i <= n; i++){
        customer.push_back(ii(ll[i], i));
        customer.push_back(ii(rr[i], n + i));
    }

    sort(customer.begin(), customer.end());

    int cnt = 0;
    int cntPos = 1;
    for(int i = 0; i < customer.size(); i++){
        int pos = customer[i].second;
        if(i == 0 || customer[i].first != customer[i-1].first)
            cnt++;
        if(pos <= n) ll[pos] = cnt;
            else rr[pos - n] = cnt;
    }

    for(int i = 0; i < customer.size(); i++){
        int pos = customer[i].second;
        if(pos <= n){
            l[cntPos] = ll[pos];
            r[cntPos] = rr[pos];
            cost[cntPos] = ccost[pos];
            cntPos++;
        }
    }
}
int getInput(){
    cin>>n>>k;
    for(int i = 1; i <=n ;i++){
        cin>>ll[i]>>rr[i]>>ccost[i];
        rr[i]+=ll[i] + k;
    }
    formTime();
}

int update(int pos, long long val){
    for(int i = pos; i <= 2 * n; i += i & -i)
        fen[i] = max(fen[i], val);
}

long long get(int leftTime){
    long long res = 0;
    for(int i = leftTime; i>=1; i-= i & -i)
        res = max(res, fen[i]);
    return res;
}

int process(){
    for(int i = 1; i<= n; i++){
        f[i] = get(l[i]) + cost[i];
        update(r[i], f[i]);
        res = max(res, f[i]);
    }
    cout<<res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.inp","r",stdin);
    getInput();
    process();
}
