#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int res = 0;
        int n; cin >> n;
        int a[1005],b[1005];
        for (int i=0; i<n; i++) cin >> a[i];
        int m; cin >> m;
        for (int i=0; i<m; i++) cin >> b[i];
        if (n<m){
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    if (a[i]==b[j]) res++;
            cout << res << endl;
            continue;
        }
        else {
            for (int j=0; j<m; j++)
                for (int i=0; i<n; i++)
                    if (a[i]==b[j]) res++;
            cout << res << endl;
            continue;
        }
    }
    return 0;
}
