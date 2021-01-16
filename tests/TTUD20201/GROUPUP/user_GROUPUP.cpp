#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
    if (argc>1 && freopen(argv[1],"r",stdin));
    if (argc>2 && freopen(argv[2],"w",stdout));
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int &e : a) scanf("%d", &e);
        int ans = 0;
        while(a.size() > 1){
            vector<int> b;
            int t = 0;
            for (int i = 0; i+1 < a.size(); i += 2){
                t = max(t, a[i] + a[i+1]);
                b.push_back(a[i] + a[i+1]);
            }
            if (a.size() % 2) b.push_back(a.back());
            ans += t;
            swap(a, b);
        }
        cout << ans;
#ifdef GENTEST
        cerr << n << " " << ans << endl;
#endif // GENTEST
    }
}
