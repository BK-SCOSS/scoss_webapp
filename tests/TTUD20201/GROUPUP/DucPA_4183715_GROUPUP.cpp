#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int test,n;
unsigned long long ans;
queue<int> q1, q2;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> test;
    while(test--){
        int b;
        ans = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> b;
            q1.push(b);
        }
        int c, x, y, z;
        while(q1.size() != 1){
            c = -1;
            while(q1.size() != 1 && !q1.empty()){
                x = q1.front();
                q1.pop();
                y = q1.front();
                q1.pop();
                z = x+y;
                q2.push(z);
                c = max(c,z);
            }
            ans += c;
            if( !q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        cout << ans;
    }
}
