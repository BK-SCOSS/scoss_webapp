//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 11/12/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include <iostream>

using namespace std;
const int N= 1e5+2;
int a[N];
int main(){
// #ifndef ONLINE_JUDGEMENT
//     freopen("/Users/tienlong/Documents/Xcode/io/bai3.txt","r",stdin);
// //    freopen("/Users/tienlong/Documents/Xcode/io/output.txt","w",stdout);
// #endif
    int num_test;
    int n;
    int j,k;
    long long res, tmp;
    cin>>num_test;
    for (int i=0;i<num_test;++i){
        cin>>n;
        for (j=0;j<n;++j){
            cin>>a[j];
        }
        a[n]=0;
        res=0LL;
        while (n!=1){
            n=(n+1)/2;
            tmp=0LL;
            for (k=0;k<n;++k){
                a[k]= a[2*k]+a[2*k+1];
                tmp = max(tmp, (long long)a[k]);
            }
            res+=tmp;
            a[n]=0;
        }
        cout<<res<<"\n";
    }
    return 0;
}
