#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);
#define ll long long
void sort_decrease(vector<int> &a) {
    sort(a.begin(),a.end(),greater<int>());
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector<int> v(a.size()+b.size());
    merge (a.begin(),a.end(),b.begin(),b.end(),v.begin(),greater<int>());
    return v;
}
int main(){
    HNT
    int T;
    cin >> T;
    while(T--) {
        int n, m, cnt = 0;
        vector<int> a;
        vector<int> b;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        cin >> m;
        for(int i = 0; i < m; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        sort_decrease(a);
        sort_decrease(b);
        vector<int> c = merge_vectors(a,b);
        /*for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        for(int i = 0; i < m; i++){
            cout << b[i] << " ";
        }
        cout<< endl;*/
        int h = m+n;
        for(int i = 0; i < h; i++){
            if(c[i] == c[i+1]) cnt++;
        }
        cout << cnt;
    }
    return 0;
}
