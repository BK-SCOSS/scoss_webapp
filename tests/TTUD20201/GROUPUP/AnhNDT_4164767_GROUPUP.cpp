#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pob pop_back
int t, n;
map<int, int> dp;
vector<int> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.resize(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        while (1)
        {
            int now = a.size();
            if(now&1) now++;
            vector<int> b(now/2);
            int val = 0;
            for(int i = 0;i < a.size();i+=2){
                if(i+1 < a.size()){ 
                    val = max(val,a[i]+a[i+1]);
                    b[i/2] = a[i]+a[i+1];
                }
                else b[i/2] = a[i];
            }
            ans += val;
            now >>= 1;
            if(now == 1) break;
            a=b;
            a.resize(now);
        }
        cout << ans << endl;
        
    }

    return 0;
}
