#include<bits/stdc++.h>
using namespace std;
const int N=105;
int T,n,m;
int a[N];
int b[N];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        cin >> m;
        for(int j=0; j<m; j++){
            cin >> b[j];
        }
        sort(a,a+n);
        sort(b,b+m);
        int ans1=0;
        int ans2=0;
        for(int i=0; i<n; i++){
            if(binary_search(b, b+m, a[i])){
                ans1++;
            }
        }
        for(int i=0; i<m; i++){
            if(binary_search(a, a+n, b[i])){
                ans2++;
            }
        }
        if(ans2>ans1){
            cout << ans2;
        }else{
            cout << ans1;
        }
    }
    return 0;
}
