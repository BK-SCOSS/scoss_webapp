#include<bits/stdc++.h>
#define M 6
#define MAX 12

using namespace std;
int n;
int mark[MAX];
int x[MAX];
int cnt;

bool check(int v, int k){
    if(v==0 && (k==0||k==2)) return false;
    return mark[v]==0;
}

void solution(){
    int s=x[0]*1000+x[1]*100+x[2]*10+x[3]+x[2]*10000+x[4]*1000+x[5]*100+x[6]*10+x[3];
    if(s==n) cnt++;
}

void  TRY(int k){
    for(int v=0;v<=9;v++){
        if(check(v, k)){
            mark[v]=1;
            x[k]=v;
            if(k==M){
                solution();
            }else TRY(k+1);
            mark[v]=0;
        }
    }
}

int main(){
   // std::cin.ignore(32767, '\n');
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<MAX;i++){
            mark[i]=0;
        }
            cnt=0;
            TRY(0);
            cout<<cnt<<endl;
        }
        return 0;
    }


