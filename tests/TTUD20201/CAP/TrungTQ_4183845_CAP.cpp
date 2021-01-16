#include <bits/stdc++.h>

using namespace std;
int m,n,t;
int a[102],b[102];
void inPut(){
        cin >> n;
        for(int i = 1; i<=n;i++){
            cin>> a[i];
        }
        cin>> m;
        for(int i = 1; i <= m ; i++){
            cin >> b[i];
        }
}
int main()
{
    cin>> t;
    while(t--){
        int res = 0;
        long long v[10001]={0};
        inPut();
        for(int i = 1; i <=n;i++){
            for(int j=1; j<=m;j++){
                if(a[i]==b[j]/*&& v[a[i]]==0*/){
                    res++;
                 //   v[a[i]]==1;
                }
            }
        }
        cout << res;
    }
    return 0;
}
