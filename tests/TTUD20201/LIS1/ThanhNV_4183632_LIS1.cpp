#include<bits/stdc++.h>
#define MAX 100004
using namespace std;
int t,n;
int a[MAX];
vector<pair<int, int> > s;
stack<int> v;
set<int> set1;
int find_(int k, int l, int r){
    if(l>r) {
        v.push(-1);
        return -1;
    }
    if(l==r){
        v.push(l);
        if(s[l].first==k){
            return s[l].second;
        }
        else return -1;
    }
    int m=(l+r)/2;
    if(s[m].first==k) {
        v.push(m);
       return s[m].second;
    }
    else if(s[m].first<k) return find_(k, m+1, r);
    return find_(k,l, m-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>t;

    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
            set1.insert(a[i]);
            s.push_back(make_pair(a[i], -1));
        }
        int siz=set1.size();
        for(set<int>::iterator it = set1.begin(); it!=set1.end();it++){
            s.push_back(make_pair(*it, -1));
        }
        sort(s.begin(), s.end());

        int best=0;
        for(int i=0;i<n;i++){
            int tmp;
            int res=0;
            if((tmp=find_(a[i]-1, 0, siz-1))!=-1) res = 1+ tmp;
            best=max(best, res);
            v.pop();
            find_(a[i], 0, siz-1);
            int vt=v.top();
            v.pop();
            s[vt].second=max(s[vt].second, res);
        }
        cout<<best+1;
    }
    return 0;
}
