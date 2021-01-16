#include<bits/stdc++.h>
using namespace std;

int binarySearch(unsigned long long b[], int left, int right, int key){
    if(left > right ) return -1;
    int mid = (left + right)/2;
    if(key == b[mid]){
        return mid;
    }
    if(key < b[mid]){
        return binarySearch(b, left, mid-1, key);
    }
    if(key > b[mid]){
        return binarySearch(b, mid +1 , right, key);
    }
}

int main(){
    set<unsigned long long> c;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t>0){
        int n,m;
        cin>>n;
        unsigned long long a[n];
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        cin>>m;
        unsigned long long b[m];
        for(int j = 0; j < m; j++){
            cin>>b[j];
        }
        sort(b,b+m);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(binarySearch(b,0,m,a[i]) != -1){
                cnt++;
            }
        }
        cout<<cnt<<endl;
        t--;
    }
    return 0;
}
