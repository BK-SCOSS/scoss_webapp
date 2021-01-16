#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> x(vector<int> a, int n){
    vector<int> b;
    for(int i=0; i<n-1; i+=2){
        b.push_back(a[i] + a[i+1]);
    }
    if(n%2==0) return b;
    else {
        b.push_back(a[n-1]);
        return b;
    }

}
int time(vector<int> a, int n){
    if(n!=1) {
        int max = 0;
        for(int i=0; i<n-1; i+=2){
            if(a[i] + a[i+1] > max ) max = a[i] + a[i+1];
        }
        if(max > a[n-1]) max = max + 0;
        else max = a[n-1];
        vector<int> c = x(a,n);
        return max + time(c, c.size());
    }

    else return 0;
} 
int main(){
    int T; cin>>T;
    int ketqua[T+1];
    for(int p=1; p<=T; ++p){
        int n; cin>>n;
        vector<int> a;
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            a.push_back(x);
        }

        ketqua[p] = time(a,n);

    }

    for(int i=1; i<=T; ++i){
        cout<<ketqua[i]<<endl;
    }
    return 0;
}