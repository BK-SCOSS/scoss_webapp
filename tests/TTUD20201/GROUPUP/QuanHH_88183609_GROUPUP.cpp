#include <bits/stdc++.h>

using namespace std;
int t, n, a[100005];
int main(){
   cin >> t; 
   while(t--){
       
       cin >> n;
       
       for (int i = 0; i < n; ++i) cin >> a[i];
       queue<int> q; 
       int cur_max = INT_MIN;
       int ans = 0;
       for (int i = 0; i < n - 1; i += 2){
           cur_max = max(cur_max, a[i] + a[i + 1]);
           q.push(a[i] + a[i + 1]);
       }
       if (n % 2) q.push(a[n - 1]);
       ans += cur_max;
       while (q.size() != 1){
           vector<int> v;
           while (q.size()){
               int top = q.front();
               q.pop();
               v.push_back(top);
           }
           cur_max = INT_MIN;
           for (int i = 0; i < v.size() - 1; i += 2){
               cur_max = max(cur_max, v[i] + v[i + 1]);
               q.push(v[i] + v[i + 1]);
           }
           ans += cur_max;
           if (v.size() % 2) q.push(v[v.size() - 1]);
       }
       cout << ans << endl;
   }
}