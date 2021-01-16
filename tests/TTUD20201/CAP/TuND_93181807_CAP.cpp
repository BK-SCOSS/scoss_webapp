#include<bits/stdc++.h>
using namespace std;
int n,m,t;
const int N=101;
int A[N];
int B[N];
int ans;
set<int> s;
void input(){
    cin>>n;
    for(int i=0;i<N;i++) A[i]=0;
    for(int i=0;i<n;i++) cin>>A[i];
    cin>>m;
    for(int i=0;i<N;i++) B[i]=0;
    for(int i=0;i<m;i++) cin>>B[i];
}
int main(){
    cin>>t;
    while(t--){
        input();
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i]==B[j]) s.insert(A[i]);
            }
        }
        cout<<s.size();
    }
}
