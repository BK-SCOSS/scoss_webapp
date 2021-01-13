#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<pair<unsigned long long, unsigned long long>> a(t);
    
    for (int i = 0; i < t; i++) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > 1e18 || a[i].second > 1e18) {
            pair<unsigned long long, int> f;
            pair<unsigned long long, int> l;
            f.first = a[i].first / 10;
            f.second = a[i].first % 10;
            l.first = a[i].second / 10;
            l.second = a[i].second % 10;
            if (f.second + l.second < 1000) {cout<< to_string(f.first + l.first) + to_string(f.second + l.second) + "\n";}
            else cout << to_string(f.first + l.first + 1) + to_string(f.second + l.second - 10) + "\n";
        }
        else {
        cout<<a[i].first + a[i].second;
        cout<<"\n";}
    }
    
    return 0;
}