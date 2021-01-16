#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n; cin >> n;
        int res = 0;
        int a[100005];
        for (int i=0; i<n; i++) {
            cin >> a[i];
            res += a[i];
        }
        cout << 2*res << endl;
    }
    return 0;
}
