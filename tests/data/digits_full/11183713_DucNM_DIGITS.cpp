#include<bits/stdc++.h>
using namespace std;
int n, cnt;
int a[8];
bool mark[10]={false};
#define sum 1000*a[1]+100*a[2]+10*a[3]+a[4] + 10000*a[3]+1000*a[5]+100*a[6]+10*a[7]+a[4] 
bool check(int i, int k){
    if ((k==1||k==3)&&(i==0)) return false;
    else if (mark[i]) return false;
    else return true;
}
void TRY(int k){
    for (int i=0; i<=9; i++){
        if (check(i,k)){
            a[k]=i;
            mark[i] = true;
            if (k==7){
                if (sum==n) cnt++;
            }
            else TRY(k+1);
            mark[i] = false;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cnt=0;
        TRY(1);
        cout<<cnt<<endl;
    }
}