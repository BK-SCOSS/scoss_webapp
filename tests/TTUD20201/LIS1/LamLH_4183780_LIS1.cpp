#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int n,res;
int T;
int a[MAX];
int s[MAX];
void input(){
    cin >> T;
    while(T--){
            cin >> n;
            for(int i=0;i<n;i++){
                cin >> a[i];
            }
    }
}
int main(){
    input();
    s[1]=1;
    res=s[1];
    for(int i=2;i<=n;i++){
        s[i]=1;
        for(int j=1;j<=i-1;j++){
            if(a[j]==a[i]-1){
                    if(s[i]<s[j]+1){
                        s[i]=s[j]+1;
                    }
               }
        }
        if(s[i]>res)
            res=s[i];
    }
    cout << res << endl;
    return 0;
}
