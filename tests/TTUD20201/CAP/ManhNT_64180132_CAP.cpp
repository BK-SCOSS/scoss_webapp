#include<iostream>
#include<set>
using namespace std;



template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    std::set<T> c;
    for(const T &x : a){
        if(b.find(x)!=b.end()){
            c.insert(x);
        }
    }
    return c;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int T,n,m;
    long long tmp;
    cin>>T;
    for(int t=0;t<T;t++){

        set<long long> a,b,c;
        a.clear();b.clear();c.clear();
        cin>>n;

        for(int i=0;i<n;i++){
            cin>>tmp;
            a.insert(tmp);
        }
        cin>>m;

        for(int i=0;i<m;i++){
            cin>>tmp;
            b.insert(tmp);
        }
        c = set_intersection(a, b);
        cout<<c.size();


    }
}
