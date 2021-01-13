#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3, oo =1e9 +7;
//typedef pair<int, int> ii;
int t, n, res, curr, pre[100], track[100];
// H, U, S, T, O, I, C = 1000, 100, 10010, 2, 1000, 100, 10
int prepare(){
    pre[1] = 1000;
    pre[2] = 100;
    pre[3] = 10010;
    pre[4] = 2;
    pre[5] = 1000;
    pre[6] = 100;
    pre[7] = 10;
}

int updateResult(){
    if(curr == n) {
        res += 1;
        //cout<<track[1]<<track[2]<<track[3]<<track[4]<<' ';
        //cout<<track[3]<<track[5]<<track[6]<<track[7]<<track[4]<<'\n';
    }
}



int backtrack(int i){
    //if(!checkReach(i)) return 0;
    if(i > 7) {
        updateResult();
        return 0;
    }
    int jj;
    if(i != 3 && i != 1) jj = 0;
        else jj = 1;
    for(int j = jj; j <= 9; j++)
    if(!track[j]){
        curr += j * pre[i];
        track[j] = 1;
        backtrack(i+1);
        track[j] = 0;
        curr -= j * pre[i];
    }
}

int process(){
    res = 0;
    for(int i = 0; i <= 9; i++)
        track[i] = 0;
    backtrack(1);
    cout<<res<<'\n';
}

int getInput(){
    prepare();
    cin>>t;
    while(t){
        t--;
        cin>>n;
        process();
    }
}

int main(){
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    getInput();
}
