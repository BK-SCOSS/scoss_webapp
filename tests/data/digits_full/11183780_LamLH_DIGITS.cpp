#include <bits/stdc++.h>
using namespace std;
int n,t;
int x[10];
int appear[10]={0};
int ans=0;
bool check(int i,int k){
    if(i==0&&k==1)
        return false;
    if((i==0) && (k==3) && (appear[i]==0))
        return false;
    if(appear[i]==1){
        return false;
    }
        return true;
}
void solution(){
    //for(int i=1; i<=7; i++){
	//	cout << x[i] << " " ;
    //}
	//cout << endl;
    ans++;
}
void TRY(int k){
    for(int i=0;i<=9;i++){
            if(check(i,k)){
                x[k]=i;
                appear[i]=1;
                if(k==7){
                    if(x[1]*1000+x[2]*100+x[3]*10+x[4]+x[3]*10000+x[5]*1000+x[6]*100+x[7]*10+x[4]==n)
                        solution();
                }
                else TRY(k+1);
                appear[i]=0;
                }
            }
    }
int main(){
    cin >> t;
    while (t--){
        ans =0;
        cin >> n;
        TRY(1);
        cout << ans<<endl;
    }
    return 0;
}
