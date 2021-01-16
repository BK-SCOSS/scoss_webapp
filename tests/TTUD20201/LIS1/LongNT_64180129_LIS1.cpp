//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 11/12/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include <iostream>
#include <map>
#include <utility>
using namespace std;

const int N=1e5+1;
int a[N];
int incr_sub_seq[N];
map<int, int > addr;

int main(){
//     #ifndef ONLINE_JUDGEMENT
//         freopen("/Users/tienlong/Documents/Xcode/io/bai2.txt","r",stdin);
// //        freopen("/Users/tienlong/Documents/Xcode/io/output.txt","w",stdout);
//     #endif
    int num_test;
    int n;
    int res;
    cin>>num_test;
    for (int i=0;i<num_test;++i){
        cin>>n;
        res=0;
        for ( int j=1;j<=n;++j){
            cin>>a[j];
            incr_sub_seq[j]=1;
            addr[a[j]]=j;
            if (addr[a[j]-1]!=0){
                incr_sub_seq[j]=max(incr_sub_seq[j], incr_sub_seq[addr[a[j]-1]]+1);
//                cout<<"max incr at "<<j<<" "<<incr_sub_seq[j]<<"\n";
            }
            res = max(res, incr_sub_seq[j]);
        }
        cout<<res<<"\n";
    }
    
    return 0;
}
