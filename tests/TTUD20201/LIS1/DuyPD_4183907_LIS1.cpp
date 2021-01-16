#include <bits/stdc++.h>
using namespace std;

int a[100001], s[100001];
int n;

int Count(int n) {
   cin>> n;
   for(int i = 0; i < n; i++) cin >> a[i];
   s[0] = 1;
   int res = s[0];
   for (int i = 1; i < n; i++){
    s[i] = 1;
    for (int j = i-1;j >-1 ; j--){
        if (a[i] == a[j] + 1 ) {
             s[i] = s[j] + 1;
            break;
        }else if (a[i] == a[j]){
            s[i] = s[j];
            break;
        }
    }
    if (s[i] > res) res = s[i];
   }
   return res;
}

int main() {
    int T;
    cin >> T;
    int b[T];
    for (int z = 0; z < T; z++) b[z] = Count(n);
    for (int z = 0; z < T; z++) cout << b[z] << endl;
    return 0;
}
