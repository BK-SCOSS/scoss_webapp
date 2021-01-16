#include <bits/stdc++.h>
using namespace std;

const int N = 100000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m;
    cin >> t;
    while(t--){
        map<int, int> a;
        map<int, int> b;
        map<int, int>::iterator tmp;
        int x;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> x;
            if(a.find(x) != a.end()){
                a[x]++;
            }
            else{
                a.insert({x, 1});
            }
        }
        cin >> m;
        for(int i=1; i<=m; i++){
            cin >> x;
            if(b.find(x) != b.end()){
                b[x]++;
            }
            else{
                b.insert({x, 1});
            }
        }
        int dem = 0;
        for(tmp=a.begin(); tmp!=a.end(); tmp++){
            if(b.find(tmp->first) != b.end()){
                dem += min(tmp->second, b[tmp->first]);
            }
        }
        cout << dem << '\n';
        /*for(auto tmp : a){
            cout << tmp.first << " " << tmp.second << endl;
        }*/
        //cout << dem << '\n';
    }
    return 0;
}
