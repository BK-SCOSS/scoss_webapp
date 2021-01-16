#include <bits/stdc++.h>

using namespace std;

int m, ans = 0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> m;
        queue<int> q;
        int a;
        for(int i=1; i<=m; i++){
            cin >> a;
            q.push(a);
        }

        int sum = 0;
        while(!q.empty()){
            int n = q.size();
            if(n%2 == 0){
                int S = 0;
                int k = n/2;
                for(int i=1; i<=k; i++){
                    int x = q.front();
                    q.pop();
                    int y = q.front();
                    q.pop();
                    S = max(S, x+y);
                    if(!q.empty()){
                        q.push(x+y);
                    }
                }
                sum += S;
            }
            else{
                int S = 0;
                int k = (n-1)/2;
                for(int i=1; i<=k; i++){
                    int x = q.front();
                    q.pop();
                    int y = q.front();
                    q.pop();
                    S = max(S, x+y);
                    q.push(x+y);
                }
                sum += S;
                int x = q.front();
                q.pop();
                q.push(x);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
