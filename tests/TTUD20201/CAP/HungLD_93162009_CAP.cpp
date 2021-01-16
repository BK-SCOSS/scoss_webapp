#include <bits/stdc++.h>
using namespace std;

int T, a[100];

int main()
{
    cin >> T;
    while (T--)
    {   
        int res =0;
        int n, m;
        cin >> n;
        for (int i=0; i<n; i++){
            cin >> a[i];
        }
        cin >> m;
        for (int i=0; i<m; i++){
            int k;
            cin >> k;
            for (int j=0; j<n; j++){
                if (a[j]==k){
                    res++;
                    break;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}