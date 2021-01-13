// Bai3
#include <iostream>
using namespace std;
// sohuict
// 0123456

int q[7]={10010,1000,1000,100,100,10,2};
bool mark[10];
int n;
int res;

void bt(int i,int s){
    if (s>n) return;
    if (i==7){
        if (s==n) res++;
        return;
    }
    int start;
    if (i==0||i==2) start=1; else start=0;
    for (int j=start;j<=9;j++) if (!mark[j]){
        mark[j]=true;
        bt(i+1,s+j*q[i]);
        mark[j]=false;
    }
}

int main(){
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        cin>>n;
        res=0;
        bt(0,0);
        cout<<res<<endl;
    }
}