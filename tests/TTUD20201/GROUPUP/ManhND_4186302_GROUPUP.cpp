#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int n,test;
int a[MAX];
int sum = 0;


int main(){
    cin>>test;
    while(test--){
        cin>>n;
        int sl = n;
        for(int i=1;i<=n;i++){
           cin>>a[i];
        }

        while(sl!=1){
            if(sl%2 == 0){
                int maxTime = 0;
                for(int i =1;i<=sl/2;i++){
                    a[i] = a[2*i] + a[2*i-1];
                    if(maxTime < a[i]){
                        maxTime = a[i];
                    }
                }
                sum+=maxTime;
                sl = sl/2;
            }
            else{
                int maxTime2 = 0;
                for(int i=1;i<=sl/2;i++){
                    a[i] = a[2*i] + a[2*i-1];
                }
                a[(sl/2)+1] = a[sl];
                sl = sl/2+1;
                for(int i =1;i<=sl;i++){
                    if(maxTime2 < a[i]){
                        maxTime2 = a[i];
                    }
                }
                sum+=maxTime2;
            }
        }
        cout<<sum<<endl;
    }
}
