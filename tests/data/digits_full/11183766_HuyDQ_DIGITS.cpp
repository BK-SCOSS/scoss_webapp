#include<bits/stdc++.h>
using namespace std;
#define MAX 50
int a[MAX];//mang cac phan tu tuong ung voi cac chu cai
int n;
int xh[MAX];//danh dau vi tri da tham
int cnt;
int T;
void input(){
    cnt=0;
    cin>>n;
}
void solution(){
    if(a[1]*1000+a[2]*100+a[3]*10+a[4]+a[3]*10000+a[5]*1000+a[6]*100+a[7]*10+a[4]==n){
        cnt++;
    }
}
bool check(int v,int k){
    if(v==0&&k==1) return false;
    if(v==0&&k==3&&xh[v]==0)return false;
    if(xh[v]==1) return false;
    return true;
}

void TRY(int k){
    for(int v=0;v<=9;v++){
        if(check(v,k)){
            xh[v]=1;
            a[k]=v;
            if(k==7) solution();
            else TRY(k+1);
            xh[v]=0;
        }
    }
}
int main(){
    for(int i=0;i<=9;i++){
        xh[i]=0;
    }
    cin>>T;
    while(T--){
        input();
        TRY(1);
        cout<<cnt<<endl;
    }

    return 0;
}
