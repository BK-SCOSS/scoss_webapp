#include<bits/stdc++.h>
using namespace std;
int n,test = 0;
const int MAX = 100005;
long long a[MAX];
long long s[MAX];
int dbest = -1;


void slove(){
    s[0] = 1;
    for(int i=1;i<n;i++){
        s[i] = 1;
        for(int j=i-1;j>=0;j--){
            if(a[i] == (a[j] +1)){
                if(s[j]+1 > s[i]){
                    s[i] = s[j] + 1;
                    break;
                }
            }
        }
        if(dbest < s[i]){
            dbest = s[i];
        }
    }
}

void reset(){
    for(int i=0;i<n;i++){
        s[i] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>test;
    while(test--){
        dbest = -1;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            s[i] = 1;
        }
        slove();
        cout<<dbest<<endl;
    }
}
