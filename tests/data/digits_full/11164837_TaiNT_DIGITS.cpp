#include <bits/stdc++.h>
using namespace std;

bool check(int hust, int soict){
    if(soict > 99999 || soict < 10000) return false;
    int t1 = hust%10;
    hust /= 10;
    int s1 = hust%10;
    hust /= 10;
    int u = hust%10;
    hust /=10;
    int h = hust%10;

    int t2 = soict%10;
    soict /= 10;
    int c = soict%10;
    soict /= 10;
    int i = soict%10;
    soict /= 10;
    int o = soict%10;
    soict /=10;
    int s2 = soict%10;

    if(t1 != t2) return false;
    if(s1 != s2) return false;
    set<int> Y;
    Y.insert(t1); Y.insert(s1); Y.insert(u); Y.insert(h); Y.insert(t2); Y.insert(c); Y.insert(i); Y.insert(o); Y.insert(s2);
    if(Y.size() != 7) return false;
    return true;
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int ans = 0;
        int hust, soict;
        for(int hust=1000; hust<=9999; hust++){
            soict = n - hust;
            if(check(hust, soict)) ans++;
        }
        cout << ans << endl;

    }

    return 0;
}