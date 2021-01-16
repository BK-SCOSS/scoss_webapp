#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while(T--){
        int ans = 0;
        int n, m;
        unsigned long long tmp;
        vector<unsigned long long> a;
        vector<unsigned long long> b;

        cin >> n;
        for(int i=0; i<n; i++){
            cin >> tmp;
            a.push_back(tmp);
        }
        sort(a.begin(), a.end());
        cin >> m;
        for(int i=0; i<m; i++){
            cin >> tmp;
            b.push_back(tmp);
        }
        sort(b.begin(), b.end());

        unsigned long long a_end = -1;
        unsigned long long b_end = -1;
        for(int i=0; i<n; i++){
            if(a[i] == a_end) continue;
            for(int j=0; j<m; j++){
                if(b[j] == b_end) continue;
                if(a[i] == b[j]) ans++;
                
                b_end = b[j];
            }
            a_end = a[i];
        }
        cout << ans << endl;
    }
    return 0;
}