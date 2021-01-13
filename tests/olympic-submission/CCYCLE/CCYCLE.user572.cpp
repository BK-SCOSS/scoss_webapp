#include<bits/stdc++.h>
using namespace std;

const int N=30004;
int n, L, S, T, f[N][1004], mod=1000000007;
vector<int> a[N];

void build() {
    for(int i=2;i<=3*n;i++) {
        if(i%3==1) {
            a[i].push_back(i-1);
            a[i-1].push_back(i);
            a[i].push_back(i+1);
            a[i+1].push_back(i);
            a[i].push_back(i+2);
            a[i+2].push_back(i);
        }
    }
    a[3*n].push_back(1);
    a[1].push_back(3*n);
    a[3*n].push_back(3*n-2);
    a[3*n-2].push_back(3*n);
    a[1].push_back(2);
    a[2].push_back(1);
    a[1].push_back(3);
    a[3].push_back(1);
}

int cal(int x, int l) {
    if(f[x][l] != -1) return f[x][l];
    if(l==L) {
        if(x==T) {
            f[x][l] = 1;
            return 1;
        }
        f[x][l]=0;
        return 0;
    }
    f[x][l] = 0;
    for(int i=0;i<a[x].size();i++) {
        int y=a[x][i];
        f[x][l] = (f[x][l] + cal(y, l+1)) % mod;
    }
    return f[x][l];
}

int main() {
    //freopen("D.INP", "r", stdin);
    //freopen("D.OUT", "w", stdout);
    cin>>n>>L>>S>>T;
    build();
    memset(f, 255, sizeof(f));
    cout<<cal(S,0);
}
