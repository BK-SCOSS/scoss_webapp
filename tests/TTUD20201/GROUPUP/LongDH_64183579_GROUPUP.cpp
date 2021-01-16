#include<bits/stdc++.h>
#define Max 100005
using namespace std;
int a[Max];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        vector<int> res;
        while(n>1){
            int tmp=0;
            //cout<<n<<endl;
            for(int i=1;i<n;i+=2){
                a[(i+1)/2]=a[i]+a[i+1];
                //cout<<a[(i+1)/2]<<" ";
                tmp = max(tmp,a[(i+1)/2]);
            }
            //cout<<endl<<tmp<<endl;
            res.push_back(tmp);
            if(n%2){
                int t=a[n];
                n = (n+1)/2;
                a[n] = t;
            }
            else n=n/2;
        }
        int ans=0;
        for(int i=0;i<res.size();i++){
            ans += res[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
