#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int main(){
      int n; cin >> n;
      int a[MAXN];
      for(int i =0; i<=n; i++){
            cin >> a[i];
      }
      int m;
      cin >> m;
      int b[MAXN];
      for(int j = 0; j <=m; j++){
            cin >> b[j];
      }
      int tmp =0;
      for( int i =0; i <=n; i++){
            for(int j =0; j<=m; j++){
                  if(a[i] == a[j]){
                        tmp += 1;
                  }
            }
      }
      cout << tmp << endl;
}
