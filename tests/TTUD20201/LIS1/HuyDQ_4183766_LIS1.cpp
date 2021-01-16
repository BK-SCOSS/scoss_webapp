#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

int T;
int n;
int a[MAX];
int s[MAX];//s[i] : gia tri bai toan con lon nhat tinh den i
int res;

void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
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
            res=max(res,s[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}
