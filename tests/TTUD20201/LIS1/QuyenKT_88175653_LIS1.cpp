#include<bits/stdc++.h>
using namespace std;
int a[10001],n;
int mem[10011];
void init(){
      memset(mem, -1, sizeof(mem));

}
int lis( int i ){
      if(mem[i] != -1) return mem[i];
      int tmp =1;
      for(int j =0; j <i; j++){
            if( a[j] < a[i]){
                  tmp = max(tmp, lis(j)+1);

            }
            mem[i] = tmp;
            return tmp;
      }

}
int main(){
      init();
      cin >> n;
      for(int i =0; i < n; i++) cin >> a[i];
      int res = 1, pos =0;
      for(int i =1; i < n; i++){
            if( res < lis(i)){
                  res = lis(i);
                  pos = 1;

            }
      }
      cout << res << endl;
      return 0;


}
