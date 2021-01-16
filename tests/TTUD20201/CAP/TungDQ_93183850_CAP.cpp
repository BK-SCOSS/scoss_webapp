#include <bits/stdc++.h>
using namespace std;
int const MAX = 10000;
int n, m;
int a[MAX], b[MAX];


int main(){
    int test;
    cin >> test;
    for(int k = 1; k <= test; k++){
        cin >> n;
        for (int i = 0 ; i < n; i++){
            cin >> a[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++){
            cin >> b[i];
        }
        int ans = 0;
        for (int i = 0;i < n; i++){
         for (int j = 0;j < m; j++){
            if (a[i] == b[j]){
               ans++;
            }
         }
        }
        cout << ans <<endl;
    }
}
