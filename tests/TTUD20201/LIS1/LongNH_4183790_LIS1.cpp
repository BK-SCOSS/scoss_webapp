#include<bits/stdc++.h>
using namespace std;
int ans=0;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    vector<int> a(n);
    int T; cin >> T;
    for (int i=0; i<T; i++) {
    cin >> n;
    for (int &x: a) cin >> x;
    }
    vector<int> f(n);
    int result = 1;
    for (int i=0; i<n; i++){
        f[i]=0;
        for(int j=i-1; j>=0; j--) if (a[i] = a[j]+1) {
            f[i] = max(f[i], f[j]);
            ans+=1;
        }
        f[i]+=1;
        result = max(result, f[i]);
    }
    cout << ans;
    return 0;
}
