#include<bits/stdc++.h>
using namespace std;

int  T,tl[100];


/*
void find() {
    for(int i = 0; i < a.size(); i++) {
        stack<int> t;
        int kq = 1;
        t.push(a[i]);
        int cur = i+1;
        for(int j = i+1; j < a.size(); j++) {
            if(a[j] = t.top()+1) {
                t.push(a[j]);
                kq++;
            }
        }
        ans = max(ans, kq);
    }
}
*/
int main() {
    cin >> T;
    for(int l = 1; l <=T; l++) {
        vector<int> a;
        int n, ans = 1;
         cin >> n;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        
        for(int i = 0; i < a.size(); i++) {
            stack<int> t;
            int kq = 1;
            t.push(a[i]);
            int cur = i+1;
            for(int j = i; j < a.size(); j++) {
                if(a[j] == t.top()+1) {
                t.push(a[j]);
                kq++;
                }
            }
           // cout << kq;
        if(kq > ans) ans = kq;
        }
        tl[l] = ans;
    }
    for(int i = 1; i <= T; i ++) {
        cout << tl[i] << endl;
    }
}


