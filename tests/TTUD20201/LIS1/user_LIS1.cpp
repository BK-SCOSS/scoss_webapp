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
#ifdef GENTEST
        int saveN = n;
#endif // GENTEST
        int ans = 1;
        map<int, int> f;
        while(n--){
            int a;
            scanf("%d", &a);
            f[a] = max(f[a], f[a-1] + 1);
            ans = max(ans, f[a]);
        }
        cout << ans;
#ifdef GENTEST
        cerr << ans << " (n = " << saveN << ")" << endl;
#endif // GENTEST
    }
}
