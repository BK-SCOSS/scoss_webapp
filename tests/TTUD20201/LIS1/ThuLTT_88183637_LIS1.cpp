#include<iostream>
#include<vector>
using namespace std;
int mem[100001];
int n;
int INF = -999999999;

int Try(int x, int a[]){
    if(x<0) return 0;
    if(mem[x] != -1) return mem[x];
    int tmp = 1;
    for(int i= x-1; i>=0; i--){
        if(a[i] == (a[x]-1)){
            tmp = max(Try(i, a)+1, tmp);
        }
    }
    mem[x] = tmp;
    return mem[x];
}
int main(){
    vector<int> v;
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            mem[i] = -1;
        }
        int ans = 1;
        for(int i=0; i<n; i++){
            ans = max(ans, Try(i, a));
        }
        v.push_back(ans);
    }
    for(auto i=v.begin(); i != v.end(); i++){
        cout << *i << endl;
    }
}
