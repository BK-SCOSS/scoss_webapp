#include <bits/stdc++.h>
using namespace std;

int a[100000];
int mem[100000];


int lis(int i){
    if (mem[i]!=-1) return mem[i];
    int res = 1;
    for (int j=0; j<i; j++)
        if (a[j]+1 == a[i])
        res = max (res, 1+lis(j));
    mem[i] = res;
    return res;
}

int main(){
    int t;
    cin >>t;
    for (int k=0; k<t; k++){
        memset(mem,-1,sizeof(mem));
        int n,mx=0;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];
        for (int i=0; i<n; i++)
            mx = max (mx, lis(i));
        cout << mx << endl;
    }
}


