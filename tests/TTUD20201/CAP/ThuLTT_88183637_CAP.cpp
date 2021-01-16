#include<iostream>
#include<vector>
#include<set>
using namespace std;
int test, n, m, x;
vector<int> v;
//int hop(const set<int> &a, const set<int> &b) {
//    set<int> c;
//    for(auto i=a.begin(); i!=a.end(); i++){
//        for(auto j=b.begin(); j!=b.end(); j++){
//            if(*i == *j) c.insert(*i);
//        }
//    }
//    return c.size();
//}
int main(){
    cin >> test;
    while(test--){
        set<int> a, b, c;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> x;
            a.insert(x);
        }
        cin >> m;
        for(int i=0; i<m; i++){
            cin >> x;
            b.insert(x);
        }
        for(auto i=a.begin(); i!=a.end(); i++){
        for(auto j=b.begin(); j!=b.end(); j++){
            if(*i == *j) c.insert(*i);
            }
        }
        v.push_back(c.size());

    }
    for(auto i=v.begin(); i != v.end(); i++){
        cout << *i << endl;
    }
}
