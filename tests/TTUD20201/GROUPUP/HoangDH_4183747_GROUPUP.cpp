#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
int n;
int T;
int a[MAX], b[MAX];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int _max = 0;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (n != 1) {
        for (int i = 1; i <= (n)/2; i++) {
            a[i] = a[2*i-1] + a[2*i];
            //a[2*i] = a[i];


      //      cout << "a[" << i << "] = " << a[i] << endl;
        //    cout << "b[" << i << "] = " << b[i] << endl;

            _max = max(_max, a[i]);


        }
        if (n % 2 == 1) a[n/2 + 1] = a[n];
      //  cout << ans <<" "<< _max << endl;

            ans += _max;
        n = (n + 1) / 2;
    }
    cout << ans << endl;
  }
}
