#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x, y;
    cin>>t;
    while(t--){
        cin>>n;
        int res = 0, ans = 0;
        queue<int> q;
        int temp;
        for (int i = 0; i<n; i++){
            cin>>temp;
            q.push(temp);
        }
        if (n%2==1) {
            q.push(0);
            n++;
        }
        n/=2;
        while (q.size()!=1) {
            for (int i=0; i<n; i++){
                x = q.front();
                q.pop();
                y = q.front();
                q.pop();
                temp = x+y;
                res = max(temp, res);
                q.push(temp);
            }
            ans += res;
            if (n%2==1&&n>1) {
                q.push(0);
                n++;
            }
            n/=2;
        }
        q.pop();
        cout<<ans<<endl;
    }
}