#include<stdio.h>

int X[7];
int appear[10];
int ans;
long N;
int solan;

void solution(){
    //int T = X[0]*1000+ X[1]*100+X[2]*10010+X[3]*2+ X[4]*1000+X[5]*100+X[6]*10;
    long T = X[0]*1000+X[1]*100+X[2]*10 + X[3] +X[2]*10000 + X[4]*1000 + X[5]*100+ X[6]*10 +X[3];
    //int T= X[0]*100 + X[1]*10+ X[2]- X[3]*100 -62 + X[4]*1000 + X[5]*100+ X[6]*10+ X[2];
    if(T == N){
        ans ++;
    }
}
void init(){
    for(int v=0; v<=9; v++){
        appear[v]=0;
    }
}
bool check(int v, int k){//thu v cho X[k]
    if(appear[v]==1) return 0;
    if(k==0 && v==0)return 0;
    if(k==2 && v==0)return 0;
    return 1;

}
void TRY(int k){
    for(int v=0; v<=9;v++){
        if(check(v,k)){
            X[k]=v;
            appear[v]=1;
            if(k == 6){
                solution();
            }
            else{
                TRY(k+1);
            }
            appear[v]=0;
        }
    }
}
void solve(){
    scanf("%ld",&N);
    init();
    ans=0;
    TRY(0);
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&solan);
    while(solan--){
    solve();}
}