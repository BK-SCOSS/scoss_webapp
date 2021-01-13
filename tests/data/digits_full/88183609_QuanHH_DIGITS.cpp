#include <bits/stdc++.h>


using namespace std;
int t, n;
int digit[7];
int vis[10];
long long ans;
bool check(){
    return digit[0]*1000 + digit[1]*100+ digit[2]*10 + digit[3] * 2 + digit[2]*10000 + digit[4]*1000 + digit[5]*100 + digit[6]*10 == n;
}
void Try(int k){
    for (int i = 0; i < 10; ++i){
        //cout << "inside for" << endl;
        if ((k == 0 || k == 2) && i == 0) continue;
        if (!vis[i]){
            digit[k] = i;
            vis[i] = 1;
            if (k == 6){
                //cout << "here" << endl;
                if (check()) ans++;
            }
            else Try(k + 1);
            vis[i] = 0;
        }
    }
}
int main(){
    cin >> t;
    while (t--){
        cin >> n;
        Try(0);
        cout << ans << endl;
        ans = 0;
    }
    // Try(0);
    // cout << ans;
}