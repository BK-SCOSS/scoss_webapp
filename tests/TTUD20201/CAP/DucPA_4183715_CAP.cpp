#include <bits/stdc++.h>
using namespace std;
#define MAX 999

int test, n, m, a[MAX], b[MAX], ans;

bool findi(int v){
    for( int j = 0; j < n; j++){
        if( v == a[j]) return true;
        if( v < a[j]) break;
    }
    return false;
}

int main(){
    cin >> test;
    while(test--){
        ans = 0;
        cin >> n;
        for( int i = 0; i < n; i++ ) cin >> a[i];
        cin >> m;
        for( int i = 0; i < m; i++ ) cin >> b[i];
        sort(a,a+n);
        for( int i = 0; i < m; i++){
            if(findi(b[i])) ans++;
        }
        cout << ans;
    }
}
