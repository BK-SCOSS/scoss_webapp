#include <iostream>
#include <vector>
#include<map>
using namespace std;
int T,n;
long *arr = new long[n];

map <long,long>v;
map <long, long> p;

int main(){
    cin>>T;
    int * c = new int [T];
    int i = 0;
    for(int k = 0; k<T; ++k){
        cin>>n;
        p.clear();
        for(i; i<n; ++i){
            cin>>arr[i];
        }
        // for(i = 0; i<=n; ++i){
        //     TRY(i,k,arr[i]);
        //     ++k;
        // }
        // cout<<i;
        // // cout<<x.size()<<endl;
        // --T;
        long res = 0;
        for (int i = 0; i<n;++i){
            long p = arr[i];
            long q = v[p-1]+1;
            v[p] = max(v[p],q);
            res = max(res,v[p]);
        }
        c[k] = res;
    }
    for (int k = 0; k< T; ++k){
        cout<<c[k]<<endl;
    }
    // system("pause");
    return 0;
}