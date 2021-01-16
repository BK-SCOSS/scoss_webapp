#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int cnt[10];
    for(int t=1; t<=T; t++){
        int n, m;
        int a[100];
        int b[100];
        cnt[t] = 0;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        cin >> m;
        for(int i=0; i<m; i++){
            cin >> b[i];
        }
        sort(b, b+m);
//        for(int i=0; i<n; i++){
//            cout << a[i];
//        }
//        for(int i=0; i<m; i++){
//            cout << b[i];
//        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i]==b[j]){
                    cnt[t]++;
                    break;
                }
            }
        }
        cout << cnt[t] << endl;

    }

    return 0;
}
