#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

int T;
int n;
int a[MAX];

void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        input();
        int time=0;
        while(n>1){
            if(n%2==0){
                int cnt=1;
            int max_group=0;
            for(int i=1;i<=n;i+=2){
                a[cnt]=a[i]+a[i+1];
              // cout<<a[cnt]<<" ";
                max_group=max(max_group,a[cnt]);
                cnt++;
                }
              //  cout<<"max_group "<<max_group<<" ";
                time+=max_group;
              //  cout<<time<<endl;
                n=n/2;
            }else{
                int cnt=1;
                int tmp=a[n];
                int max_group=a[n];
                for(int i=1;i<=n-2;i+=2){
                a[cnt]=a[i]+a[i+1];
              //  cout<<a[cnt]<<" ";
                max_group=max(max_group,a[cnt]);
                cnt++;
                }
                a[cnt]=tmp;
               // cout<<"max_group "<<max_group<<" ";
                time+=max_group;
               // cout<<time<<endl;
                n=(n/2)+1;
            }
        }
        cout<<time<<endl;
    }


}
