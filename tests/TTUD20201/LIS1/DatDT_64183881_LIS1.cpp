#include <iostream>
#include <stdlib.h>
using namespace std;

int run(int a[], int n){
    int l[n];
    l[0] = 1;
    int lmax;
    for(int i=0; i<n; ++i){
        lmax = 0;
        for(int j=0; j<i; ++j){
            if(a[i] - a[j] == 1) 
                if(l[j] > lmax) lmax = l[j];
            }
        l[i] = lmax + 1;
    }

    int max =0;
    for(int i=0; i<n; ++i){
        if(l[i] > max) max = l[i];
    }
    return max;

}

int main(){
    int T; cin>>T;
    int ketqua[T+1];
    for(int p=1; p<=T; ++p){
        int n; cin>>n; 
        int a[n];
        for(int i=0; i<n; ++i){
            cin>>a[i];
        }
        // int l[n];
        // l[0] = 1;
        // int lmax;
        // for(int i=0; i<n; ++i){
        //     lmax = 0;
        //     for(int j=0; j<i; ++j){
        //         if(a[i] - a[j] == 1) 
        //            if(l[j] > lmax) lmax = l[j];
        //     }
        //     l[i] = lmax + 1;
        // }
        ketqua[p] = run(a, n);

    }

    for(int i=1; i<=T; ++i){
        cout<<ketqua[i]<<endl;
    }
    return 0;





   


    


}