#include <bits/stdc++.h>
using namespace std;

int n, m, k;
set <unsigned long long> a,b;
int res[10];

int main(){
    memset(res, 0, sizeof(res));
    cin >> k;
    for(int q=0; q<k; q++){
    cin >> n;
    for(int i=0; i<n; i++){
        unsigned long long x;
        cin >> x;
        a.insert(x);
    }
    cin >> m;
    for(int i=0; i<m; i++){
        unsigned long long y;
        cin >> y;
        b.insert(y);
    }
    for(unsigned long long u : a){
        for(unsigned long long v : b){
            if(u==v) res[q]++;
        }
    }
    }
    for(int i=0; i<k; i++){
        cout << res[i] << endl;
    }
}
