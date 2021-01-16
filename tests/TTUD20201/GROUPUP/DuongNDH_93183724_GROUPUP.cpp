#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
queue<int> q;
int n, ans[11];
void input(){
    cin>>n;
    for(int i = 0; i< n; i++){
        int a;
        cin>>a;
        q.push(a);
    }
}
int solve(){
    int time = 0;
    while(q.size()>1){
        int s = q.size();
        int tmax = 0;
        for(int i = 0; i< s/2; i++){
            int g1 = q.front();
            q.pop();
            int g2 = q.front();
            q.pop();
            q.push(g1+g2);
            tmax = max(tmax, g1+g2);
        }
        if(s%2){
            int g = q.front();
            q.pop();
            q.push(g);
        }
        time = time + tmax;
    }
    return time;
}

int main(){
    int loop;
        cin>>loop;
        int i = 0;
        while(i != loop){
            while(!q.empty()){
                q.pop();
            }
            input();
            ans[i] = solve();
            i++;
        }
        for(int i = 0; i< loop;i++ ){
            cout<<ans[i]<<endl;
        }

}
