#include<bits/stdc++.h>
using namespace std;
#define MAX 104

int T;
int n[MAX];
int a[MAX][MAX];
int res;
int sum;

int countArray(int k, int b[MAX][MAX]){
    // res=0;
    if(n[k]%2==0){
        for(int i=1;i<=n[k]-1;i+=2){
            for(int j=2;j<=n[k];j+=2){
                if(res<b[k][i]+b[k][j]){
                    res=b[k][i]+b[k][j];
                }
                sum+=res;
                b[k][j/2]=b[k][i]+b[k][j];
                for(int x=(n[k]/2)+1;x<=n[k];x++){
                    b[k][x]=0;
                }
                n[k]=n[k]/2;
                if(n[k]==1){
                    return sum;
                }
                else return countArray(k,b);
            }
        }
    }
    else{
        for(int i=1;i<=n[k]-2;i+=2){
            for(int j=2;j<=n[k]-1;j+=2){
                if(res<b[k][i]+b[k][j]){
                    res=b[k][i]+b[k][j];
                }
                sum+=res;
                b[k][j/2]=b[k][i]+b[k][j];
                b[k][(n[k]-1)/2+1]=b[k][n[k]];
                for(int x=(n[k]-1)/2+1;x<=n[k];x++){
                    b[k][x]=0;
                }
                n[k]=(n[k]-1)/2+1;
                return countArray(k,b);
            }
        }
    }
}
int main(){
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n[i];
        for(int j=1;j<=n[i];j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=T;i++){
        res=0;
        sum=0;
        cout<<countArray(i,a);
    }
}

