#include<bits/stdc++.h>
using namespace std;
int t;
int n;
const int N=1e5+1;
int A[N];
int ans[N];
int result;
int tmp;
void input(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];
}
int main(){
    cin>>t;
    while(t--){
        input();
        result=0;
        for(int i=0;i<n;i++){
            ans[i]=1;
            tmp=A[i];
            for(int j=i+1;j<n;j++){
                if(A[j]==tmp+1){
                    ans[i]++;
                    tmp=A[j];
                }
            }
        }
       for(int i=0;i<n;i++){
            if(ans[i]>result) result=ans[i];
       }
       cout<<result;
    }
}
