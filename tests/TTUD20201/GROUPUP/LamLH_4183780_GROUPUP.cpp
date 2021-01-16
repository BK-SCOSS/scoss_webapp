#include<bits/stdc++.h>
using namespace std;
const int MAX =100005;
int T;
int n;
int a[MAX];int b[MAX];
int max_time=0;
int ans;
void input(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
    }
}
int main(){
    ans =0;
    input();
    while(n>1){

        if(n%2==0){

        for(int i=1;i<=n/2;i++){
            a[i]=a[2*i]+a[2*i-1];
            max_time = max(max_time,a[i]);
        }
        ans+=max_time;
        n=n/2;
        }
        else {
            int i;
            max_time=a[n];
            for(i=1;i<=(n-1)/2;i++){
                a[i]=a[2*i]+a[2*i-1];
                max_time=max(max_time,a[i]);
            }
            a[i+1]=a[n];
            ans+=max_time;
            n=n/2+1;
    }
    }
    cout << ans << endl;
}
