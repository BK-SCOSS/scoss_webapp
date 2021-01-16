#include <iostream>
#include <set>
using namespace std;

int t,n,m;
bool ck[1000000005];
template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    set<T> c;
    for (const T &x : a) {
        if( ck[x])
            continue;
        if (b.find(x) != b.end()) {
            c.insert(x);
            ck[x] = true;
        }
    }
    return c;
}

int main()
{
    cin>>t;
    set<int> a;
    set<int> b;
    int x;
    while(t--){
        cin>>n;
        for(int i = 0 ; i<n; ++i){
            cin>>x;
            a.insert(x);
        }
        cin>>m;
        for(int i=0; i<m; ++i){
            cin>>x;
            b.insert(x);
        }
        set<int> c = set_intersection(a,b);
        cout<<c.size()<<endl;
    }
    return 0;
}
