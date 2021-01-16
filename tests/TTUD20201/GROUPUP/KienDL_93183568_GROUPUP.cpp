#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+1;
int n;
int T;
int a[MAX];
int rs;
vector<int> tmp;

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tmp.push_back(a[i]);
    }
}

void solve(){
    cin >> T;
    for(int k = 1; k <= T; k++){
        rs = 0;
        input();
        int cnt = 0;
        //int loop = (int) log2(n) + 1;
        while(cnt != 1){
            int t = 0;
            cnt = 0;
            for(int j = 1; j <= n; j+=2){
                if(j == n){
                    cnt++;
                    a[cnt] = a[j];
                    t = max(t, a[j]);
                }
                else{
                    int c = a[j] + a[j+1];
                    cnt++;
                    a[cnt] = c;
                    t = max(t, c);
                }
            }
            n = cnt;
            rs += t;
        }

        cout << rs << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


