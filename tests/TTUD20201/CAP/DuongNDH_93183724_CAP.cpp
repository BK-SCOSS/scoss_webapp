#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int ans[N+1];
int n1, n2;
set<int> s1, s2;
void input(){
    cin>>n1;
    for(int i = 0; i< n1; i++){
        int a;
        cin>>a;
        s1.insert(a);
    }
    cin>>n2;
    for(int i = 0; i<n2; i++){
        int a;
        cin>>a;
        s2.insert(a);
    }
}

int solve(){
    int chung = 0;
    for(set<int>::iterator it = s1.begin(); it != s1.end(); it++ ){
        if(s2.find(*it)!= s2.end()){
            chung++;
        }
    }
    return chung;

}
int main(){
    int n;
    cin>>n;
    int i = 0;
    while(i!= n){
        s1.clear();
        s2.clear();
        input();
        ans[i] = solve();
        i++;
    }
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<endl;
    }

}
