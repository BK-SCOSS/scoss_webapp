#include<bits/stdc++.h>
using namespace std;
#define MAX 10
bool visited[MAX];//0,1,23456789,51 hàng
int x[51][6];//S,H,O,U,I,C,T
int t;
int cnt=0;
long long*n=new long long[t];
//HUST+SOICT=n
void input(){
    for(int i=0;i<t;i++) cin>>n[i];
    cout<<endl;
}
bool check(){
    for(int i=0;i<t;i++){
    if(x[i][0]*10000+(x[i][1]+x[i][2])*1000+(x[i][3]+x[i][4])*100+(x[i][5]+x[i][0])*10+2*x[i][6]==n[i]) return true;
    }
    //if(x[0]==0) return false;
    return false;  
}
void TRY(int k){
    for(int i=0;i<t;i++){
        for(int v=1;v<=9;v++){
         if(!visited[v]){
            x[i][k]=v;
            visited[x[i][k]]=true;
               if(k==6) {
                   if(check()) {
                    cnt++;
                }    
                else TRY(k+1);
            }
         }    
            visited[x[i][k]]=false;
        }
    }
}
int main(){
    cin>>t;
    input();
    for(int i=0;i<t;i++){
        TRY(0);
        cout<<cnt<<endl;
    }
}
/*5
17868
29119
49862
78952
1000002*/