#include <bits/stdc++.h>
using namespace std;

int T, a[100001], mem[100001], n;

int f(int k){
    if (k==0){ 
        mem[k]=1;
        return 1;
    }
    if (mem[k]!=-1) return mem[k];

    int res =1;
    for (int i=k-1; i>=0; i--){
        if(a[i]==a[k]-1) {
            res+=f(i);
            break;
        }
    }
    mem[k]=res;
    return res;
}

int main()
{   
    // freopen("/Users/apple/Desktop/AppliedAlgo-20201/VD5/LISS1.inp", "r", stdin);
    cin >> T;
    while (T--)
    {   
        memset(mem, -1, sizeof(mem));
        int res=0;
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];

        for (int i=n-1 ;i>=0; i--){
            res = max(res, f(i));
        }

        cout << res << endl;
    }

    return 0;
}