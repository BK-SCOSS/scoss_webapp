#include <bits/stdc++.h>

#define MAX 1000001
#define LON 100000000
using namespace std;

unsigned long long A[MAX];
int n, rs=0;
vector<int> kq;

void input(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i=0;i!=n;i++){
        cin >> A[i];
    }
}

void slove(){
    for(int i=0;i!=n;i++){
        kq[A[i]] = kq[A[i]-1] +1;
        int tmp = kq[A[i]];
        rs = rs > tmp ? rs : tmp;
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        input();
        kq.resize(LON);
        slove();
        cout << rs << endl;
    }
    return 0;
}
