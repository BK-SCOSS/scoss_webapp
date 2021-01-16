#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7, N = 1e5 + 3;
typedef struct Element{
    int val;
    int pos;
} Element;

int t, n, a[N], f[2 * N], minn, res;
vector<Element> vt;

int getInput(){
    cin>>n;

    vt.clear();
    minn = oo;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        Element e;
        e.val = a[i];
        e.pos = i;
        vt.push_back(e);
        minn = min(minn, a[i]);
    }
}

bool comparator(Element e1, Element e2){
    if(e1.val < e2.val) return true;
        else if(e1.val == e2.val) return (e1.pos < e2.pos);
    return false;
}

int normalize(){
    int curr = 0;

    for(int i = 1; i < vt.size(); i++){
        if(vt[i].val == vt[i-1].val){
            a[vt[i].pos] = curr;
            continue;
        }

        if(vt[i].val > vt[i-1].val + 1){
             curr += 2;
             a[vt[i].pos] = curr;
             continue;
        }

        if(vt[i].val == vt[i-1].val + 1){
            curr += 1;
            a[vt[i].pos] = curr;
            continue;
        }
    }
}

int prepare(){

    Element e;
    e.pos = 0;
    e.val = minn - 1;
    vt.push_back(e);
    sort(vt.begin(), vt.end(), comparator);
    normalize();

    for(int i = 1; i <= 2 * n; i++)
        f[i] = 0;
}

int process(){
    res = -oo;
    for(int i = 1; i <= n; i++){
        f[a[i]] = f[a[i] - 1] + 1;
        res = max(res, f[a[i]]);
    }

    cout<<res<<'\n';
}

int main(){
    //freopen("test.inp", "r", stdin);
    cin>>t;
    while(t){
        t--;
        getInput();
        prepare();
        process();
    }
}
