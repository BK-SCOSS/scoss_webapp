#include <bits/stdc++.h>
using namespace std;

string add_big_num(string a, string b);

signed main(){
#ifdef LOCAL_DEBUG
  freopen("test-inp.txt", "r", stdin);
#endif
  int t; cin>>t;
  while(t--){
    string a, b; cin >> a >> b;
    cout << add_big_num(a, b)<< "\n";
  }
  return 0;
}

string add_big_num(string a, string b){
  if(a.length() < b.length()){
    return add_big_num(b, a);
  }
  string res = "";
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  while(b.length() < a.length()) b.push_back('0');
  int sur = 0;
  for(int i=0; i< a.length(); ++i){
    int u = (a[i]-'0' + b[i]-'0' + sur);
    if(u >= 10){
      res.push_back((char)'0'+(u-10));
      sur = 1;
      continue;
    } 
    res.push_back((char)'0'+ u);
    sur = 0;
  }
  if(sur > 0){
    res.push_back((char)'0'+sur);
  }
  reverse(res.begin(), res.end());
  return res;
}