#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);

int main(){
    HNT
    int T;
    cin >> T;
    while(T--) {
        int n, res = 0;
        cin >> n;
        int a[n], start[n], cnt[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            start[i] = a[i];
            cnt[i] = 1;
        }
        int m = 96*n/97;
        for(int i = m; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                 if(start[i] == a[j] + 1){
                    start[i] = a[j];
                    cnt[i]++;
                }
            }
            res = max(res, cnt[i]);
        }
        cout << res <<endl;
    }
    return 0;
}
