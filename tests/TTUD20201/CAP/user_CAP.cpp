#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
    if (argc>2){
        freopen(argv[1],"r",stdin);
        freopen(argv[2],"w",stdout);
    }
    int t;
    cin >> t;
    while(t--){
        set<int> a;{
            int n;
            cin >> n;
            while(n--){
                int x;
                cin >> x;
                a.insert(x);
            }
        }
        int ans = 0;{
            int n;
            cin >> n;
            while(n--){
                int x;
                cin >> x;
                ans += a.count(x);
            }
        }
        cout << ans << endl;
#ifdef GENTEST
        cerr << ans << endl;
#endif // GENTEST
    }
}
