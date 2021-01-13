#include <bits/stdc++.h>

using namespace std;
int T;
int n;
int x[50];
bool mark[50];
int cnt ;
int ans[60];


void input(){
    cin >> n;
    for(int j = 50; j > 0; j--){
        mark[j] = false;
    }
}

void Try(int k){
    for(int v = 0; v <= 9; v++){
        if(!mark[v]){
            x[k] = v;
            mark[v] = true;
            if(k == 6){
                int N;
                if(x[0]!=0 && x[2]!=0)N = 1000*x[0] + 100*x[1] + 10010 * x[2] + 2*x[3] + 1000*x[4]+ 100*x[5] + 10* x[6];
                if(N == n) cnt++;
            }
            else Try(k+1);
            mark[v] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> T;
    for(int j = T; j > 0; j--){
        input();
        cnt = 0;
        Try(0);
        ans[j] = cnt;
    }

    for(int j = T; j > 0; j--) cout << ans[j] << endl;
    return 0;
}
