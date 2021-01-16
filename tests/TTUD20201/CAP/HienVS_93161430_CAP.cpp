#include<bits/stdc++.h>
using namespace std;

int n,m;
int t;
int k;
vector<int> a,b;

main(){
    cin >> t;
    while(t>0){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> k;
            a.push_back(k);
        }
        cin >> m;
        for(int i=0;i<m;i++){
            cin >> k;
            b.push_back(k);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[j]==a[i]){
                    ans++;
                    continue;
                }
            }
        }
        cout << ans << endl;
        t--;
    }
}