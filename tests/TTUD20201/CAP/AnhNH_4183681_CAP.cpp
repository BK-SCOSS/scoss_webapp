#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 3, oo = 1e9 + 7;
int t, n, m, a[N], b[N], f[N][N];
vector<int> vt1, vt2;
typedef pair<int, int> ii;
int getInput(){
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    cin>>m;
    for(int i = 1; i <= m; i++)
        cin>>b[i];
}

int normalize(){
    a[0] = -oo;
    b[0] = -oo;
    for(int i = 1; i <= n; i++)
        if(a[i] != a[i-1])
            vt1.push_back(a[i]);

    for(int i = 1; i <= m; i++)
    if(b[i] != b[i-1])
        vt2.push_back(b[i]);
}

int prepare(){
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    vt1.clear();
    vt2.clear();
    vt1.push_back(0);
    vt2.push_back(0);

    normalize();

    for(int i = 1; i < vt1.size(); i++)
    for(int j = 1; j < vt2.size(); j++)
        f[i][j] = 0;
}

int process(){
    for(int i = 1; i < vt1.size(); i++)
    for(int j = 1; j < vt2.size(); j++){
        f[i][j] = max(f[i-1][j], f[i][j-1]);
        if(vt1[i] == vt2[j]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
    }

    cout<<f[vt1.size()-1][vt2.size()-1]<<'\n';
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
