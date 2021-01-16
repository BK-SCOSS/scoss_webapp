#include<bits/stdc++.h>
using namespace std;
int res = 0;
int a[1000];
int b[1000];
int mem [1000][1000];
int lcs( int i, int j) {
if (i == -1 || j == -1) {
return 0;
}
if (mem[i][j] != -1) {
return mem[i][j];
}
res = max(res , lcs (i, j - 1));
res = max(res , lcs (i - 1, j));
if (a[i] == b[j]) {
res = max(res , 1 + lcs(i - 1, j - 1));
}
mem [i][j] = res;
return res;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset (mem , -1, sizeof (mem ));
        int n;
        cin>>n;
        for(unsigned int i=0;i<n;i++){
            cin>>a[i];
        }
        int m;
        cin>>m;
         for(unsigned int j=0;j<m;j++){
            cin>>b[j];
        }
        lcs(n-1,m-1);
        cout<<res;

    }
}
