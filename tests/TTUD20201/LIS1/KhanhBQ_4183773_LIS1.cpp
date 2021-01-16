#include <bits/stdc++.h>
using namespace std;

bool isBeautifulSequence(int a[], int n){
    for(int i = 0; i < n - 1; ++i){
        if((a[i+1]-a[i])!=1) return 0;
    }
    return 1;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; ++i){
            int u; cin >> u;
            v.push_back(u);
        }

        int res = 0;
        for(int i = 0; i < n - 1; ++i){
            vector<int> temp;
            temp.push_back(v[i]);
            for(int j = i + 1; j < n; ++j){
                if(v[j] - temp.back() == 1){
                    temp.push_back(v[j]);
                }
            }
            if(res < temp.size()) res = temp.size();
        }
        cout << res << "\n";
    }
}