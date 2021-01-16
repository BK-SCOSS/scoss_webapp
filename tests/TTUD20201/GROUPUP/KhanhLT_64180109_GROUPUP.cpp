//
//  main.cpp
//  CuoiKi.C
//
//  Created by Lê Tường Khanh on 16/01/2021.
//

#include <iostream>
using namespace std;

int t;
long n,ans;
long long a[100000];

int main(int argc, const char * argv[]) {
    cin >>t;
    for(int i = 0;i<t;i++){
        ans =0;
        cin >>n;
        for(long j =0;j<n;j++){
            cin >> a[j];
        }
        while(n>1){
            long long currMax =0;
            for(long j =0;2*j<n-1;j++){
                a[j] = a[2*j] + a[2*j+1];
                currMax = max(currMax,a[j]);
            }
            if (n % 2) a[(n-1)/2] = a[n-1];
            ans += currMax;
            n = (n+1)/2;
        }
        cout<<ans;
    }
    
    return 0;
}
