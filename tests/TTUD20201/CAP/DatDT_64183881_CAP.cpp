#include <iostream>
#include <stdlib.h>
#include <vector>
// #include <stack>
// #include <map>
// #include <queue>
using namespace std;



// int main(){

//     unsigned long long n; cin>>n;
//     unsigned long long a[n];
//     for(int i=0; i<n; ++i){
//         cin>>a[i];
//     }
//     unsigned long long m; cin>>m;
//     unsigned long long b[m];
//     for(int i=0; i<m; ++i){
//         cin>>b[i];
//     }
    
//     int max = 0;
//     for(int i=0; i<n; ++i){
//         if(a[i] > max) max = a[i];
//     }

//     int* count = new int[max];
//     for(int i=0; i<max; ++i){
//         count[i] = 0;
//     }
//     for(int i=0; i<n; ++i){
//         count[a[i]]++;
//     }

//     for(int i=0; i<m; ++i){
//         if(b[i]<=max) count[b[i]]++;
//     }

//     int c = 0;
//     for(int i=0; i<max; ++i){
//         if(count[i] == 2) ++c;
//     }

//     delete[] count;
//     cout<<c;

    
    
//     return 0;
// }

// int check(vector<int> a, vector<int> b){
//     int count =0;
//     for(int i=0; i<a.size(); ++i){
//         for(int j=0; j<b.size(); ++j){
//             if(b[j]==a[i]) ++count;
//             break;
//         }
//     }
//     return count;
// }

int run(int a[], int b[], int n, int m){
    int count =0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(b[j] == a[i]) ++count;
        }
    }
    return count;

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
        int m; cin>>m;
        int b[m];
        for(int i=0; i<m; ++i){
            cin>>b[i];
        }

        ketqua[p] = run(a,b,n,m);



    }

    for(int i=1; i<=T; ++i){
        cout<<ketqua[i]<<endl;
    }
    return 0;
}