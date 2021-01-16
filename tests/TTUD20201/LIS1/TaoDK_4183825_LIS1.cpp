#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

int T;
int n;
int a[MAX];
int ans;
int mem[MAX];

int solve(int i){
    if(mem[i] != -1) return mem[i];
    int res = 1;
    for(int j = 1; j <= i; j++){
        if(a[j] == a[i] - 1){
            res = max(res, 1 + solve(j));
        }
    }
    mem[i] = res;
    return res;
}
void input(){
    cin >> T;
    while(T > 0){
        memset(mem, -1, sizeof(mem));
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        solve(n);
        for(int i = 1; i <= n; i++){
            ans = max(ans, mem[i]);
        }
        cout << ans << endl;
        T--;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    input();
    return 0;
}
