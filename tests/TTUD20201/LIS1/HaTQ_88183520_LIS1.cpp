#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, int> a;
        int x;
        cin >> x;
        a.insert({x, 1});
        for(int i=2; i<=n; i++){
            cin >> x;
            if(a.find(x-1) != a.end()){
                if(a.find(x) != a.end()){
                    a[x] = a[x-1]+1;
                }
                else{
                    a.insert({x, a[x-1]+1});
                }
            }
            else{
                a.insert({x, 1});
            }
        }
        map<int, int>::iterator tmp;
        int ans = 0;
        for(tmp=a.begin(); tmp!=a.end(); tmp++){
            if(ans < tmp->second){
                ans = tmp->second;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
