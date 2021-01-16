//
//  main.cpp
//  CuoiKi.B
//
//  Created by Lê Tường Khanh on 16/01/2021.
//

#include <iostream>
using namespace std;

int t;
long n,ans;
long a[100000];
long dp[100000];
bool v[1000000001];
int main(int argc, const char * argv[]) {
    cin >>t;
    for(int i =0;i<t;i++){
        ans =0;
        cin >>n;
        for(long j =0;j<n;j++){
            cin >> a[j];
        }
        for(long j =0 ;j<n;j++){
            dp[j] =0;
        }
        
        v[a[0]] =true;
        for(long j= 1;j<n;j++){
            v[a[j]] =true;
            if (v[a[j]-1]) for(long k = 0;k<j;k++){
                if (a[j] - a[k] ==1){
                    dp[j] = max(dp[j],1+dp[k]);
                }
            }
        }
        for(long j=0;j<n;j++){
            ans = max(ans,dp[j]);
        }
        cout<<ans+1;
        for(long j =0;j<n;j++){
            v[a[j]] = false;
        }
    }
    return 0;
}
