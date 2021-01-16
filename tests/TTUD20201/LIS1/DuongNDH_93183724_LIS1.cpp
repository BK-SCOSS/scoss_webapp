#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int a[N], ans[10];
int n,s[N];
void input(){
    cin>>n;
    for(int i = 1; i<= n; i++){
        cin>>a[i];
    }
}
int solve(){
    s[1] = 1;
    for(int i = 2; i<= n; i++){
        s[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[j]+1 == a[i]){
                s[i] = max(s[i], s[j]+1);
            }
        }
    }
    int m = 0;
    for(int i = 1; i<= n; i++){
        m = max(m, s[i]);
    }
    return m;
}

int main(){
    int loop;
    cin>>loop;
    int i = 0;
    while(i!= loop){
        input();
        ans[i] = solve();
        i++;
    }
    for(int i = 0; i< loop; i++){
        cout<<ans[i]<<endl;
    }

}
