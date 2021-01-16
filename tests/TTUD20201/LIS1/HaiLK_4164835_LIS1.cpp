#include<bits/stdc++.h>
using namespace std;


void xx(){
    int n;
    cin >> n;
    unsigned long long a[n];
    map<unsigned long long, int> hash;

    for(int i=1; i<n; i++){
        cin >> a[i];
    }

    hash[a[0]] = 1;
    int result = 1; 

    for(int i=1; i<n; i++){
        hash[a[i]] = hash[a[i]] > hash[a[i]-1]+1 ? hash[a[i]] : hash[a[i]-1]+1;
        result = hash[a[i]] > result ? hash[a[i]] : result;
    }  

    cout << result << endl;
}

int main(){
    
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;  cin >> T;
    for(int i=0; i<T; i++) xx();
    return 0;
}