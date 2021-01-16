//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 11/12/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include <iostream>

using namespace std;

const int N=100;
int main(){
// #ifndef ONLINE_JUDGEMENT
    // freopen("/Users/tienlong/Documents/Xcode/io/bai1.txt","r",stdin);
//    freopen("/Users/tienlong/Documents/Xcode/io/output.txt","w",stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_test, j,k;
    int n,m;
    int count_ele;
    int a[N],b[N];
    cin>>num_test;
    for (int i=0;i<num_test;++i){
        count_ele=0;
        cin>>n;
        for (j=0;j<n;++j){
            cin>>a[j];
        }
        cin>>m;
        for (k=0;k<m;++k){
            cin>>b[k];
            for (j=0;j<n;++j){
                if (b[k]==a[j]){
                    count_ele++;
                    break;
                }
            }
        }
        cout<<count_ele<<"\n";
    }
    return 0;
}
