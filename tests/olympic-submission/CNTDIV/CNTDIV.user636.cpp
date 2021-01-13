#include <bits/stdc++.h>
using namespace std;
const int N =1e6 +3 ;
int t, n, dd[N];
vector<int> nt, uocSo;
int soNguyenTo(){
    for(int i = 2; i <= N - 3; i++)
    if(!dd[i])
    {
        int cnt = 2;
        while(cnt * i <= N -3){
            dd[cnt * i] = 1;
            cnt ++;
        }
    }

    for(int i = 2; i<= N -3; i++)
        if(!dd[i]) nt.push_back(i);
}
int prepare(){
    uocSo.clear();
}
int process1(){
    long long t = n * (n + 1) * (n + 2);
    //cout<<t<<'\n';
    for(int i = 0; i< nt.size(); i++){
        int val = nt[i];
        int cnt = 0;
        if(val > n + 2) break;
        while(t % val ==0){
            cnt++;
            t /= val;
        }
        if(cnt) uocSo.push_back(cnt);
    }

    int m = uocSo.size();
    long long hh = 1;
    for(int i = 1; i<= m; i++)
        hh*= 2;

    long long res= hh, r = 1;
    for(int i = 0; i< m; i++)
        res *= uocSo[i];

    for(int i = 0; i< m; i++)
        r *= uocSo[i]+1;

    res-=r;
    res--;
    cout<<res<<'\n';
}
int main(){
    //freopen("test.inp","r",stdin);
    process1();
    cin>>t;
    soNguyenTo();
    while(t){
        t--;
        cin>>n;
        prepare();
        process1();
        //getDivisors();
    }
}
