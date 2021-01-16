#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int T;
int n;
int a[N];
int s[N];
int ans;



main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> T;
    for(int v=1; v<=T; v++){
        ans = 0;
        map<int,int> ma;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            if(ma[a[i]-1] > 0){
            	ma[a[i]] = ma[a[i]-1]+1;
			}else{
				ma[a[i]] = 1;
			}
            ans = max(ans,ma[a[i]]);
        }
        
        
        cout << ans << endl;
    }
}
