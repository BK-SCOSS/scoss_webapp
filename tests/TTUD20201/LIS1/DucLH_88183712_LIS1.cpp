#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];
int n;
int res = 0;
int t;
int temp;
int g[N];
int kq = -1;
map <int, int> mapl;

void inp(){
    cin >> n;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void proc(){

    for (int i = 0; i < n; i++){
        mapl[a[i]] = 1;
        auto search = mapl.find(a[i] - 1);
        if (search != mapl.end()){
            mapl[a[i]] = search -> second + 1;

        }
        res = max(res, mapl[a[i]]);

}
}


int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--){
        inp();
        int bestj = 0;
        proc();
        cout << res << endl;
    }
}
