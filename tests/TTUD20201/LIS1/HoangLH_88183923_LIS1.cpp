#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int cas;
    cin >> cas;
    while(cas--){
        int n;
        cin >> n; 
        int a[n], dp[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
            dp[i]=1;
        }
        int maxlen=0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(a[i]-a[j]==1){
                    dp[i]+=dp[j];
                }
            }
        }
        for(int i=0; i<n; i++){
            maxlen=max(maxlen,dp[i]);
        }
        cout << maxlen << endl;
    }
}