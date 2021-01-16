#include <bits/stdc++.h>
using namespace std;

int chiphi = 0;
void UNION(vector<int> a, int n){
    if(n==1) return;
    else{
        //cout << "Lan thu " << n << endl;
        vector<int> temp;
        int max = 0;
        for(int i = 0; i < n - 1; i += 2){
            int m = a[i] + a[i+1];
            temp.push_back(m);
            if(max < m) max = m;
        }
        //cout << "max: " << max << endl;
        chiphi += max;
        //cout << "chiphi = " << chiphi << endl;
        if(n%2==1) temp.push_back(a[n-1]);
        a = temp;
        (n%2==0) ? n/=2 : n = n/2+1;
        //cout << "n: " << n << endl;
        //cout << "a: ";
        //for(auto &c: a) cout << c << " ";
        //cout << endl;
        UNION(a, n);
    }
}


int main(){
    int T;
    cin >> T;
    while(T--){
        int n; 
        cin >> n;
        vector<int> a;
        for(int i = 0; i < n; ++i){
            int xD; cin >> xD;
            a.push_back(xD);
        }
        UNION(a,n);
        cout << chiphi << "\n";
    }
}
