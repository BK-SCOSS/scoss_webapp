#include<bits/stdc++.h>

using namespace std;

const int N= 1e5+1;

int n,m;
int a[N];
int s[N];

void input(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin>> a[i];
}

int Step(int k){
    int maxsub =0;
    int i,j=0;
    int tmp1 = n/(2<<k);
    for( i=0; i <= tmp1; i++ ){
        a[i] = a[j] + a[j+1];
        maxsub = max(maxsub, a[i]);
        j+= 2;
    }
    a[i] =0;
    return maxsub;
}


void slove(){
    int ans =0;
    int m = (int)log2(n);
    for(int i =0; i<= m; i++){
        int tmp = Step(i);
        //cout << "step "<< i<< " :" << tmp << endl;
        ans += tmp;
    }
    cout << ans << endl;
}

int main(){
    int test;
    cin >> test;
    for(int i=0; i< test; i++){
        input();
        slove();
    }
    return 0;
}