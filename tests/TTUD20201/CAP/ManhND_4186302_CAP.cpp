#include<bits/stdc++.h>
using namespace std;
int test;
int n,m;
const int MAX = 105;
int a[MAX],b[MAX];
int cnt = 0;


int main(){
    cin>>test;
    while(test--){
        bool check = true;
        cnt = 0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>b[i];
        }

        for(int i=0;i<n;i++){
            for(int p = i-1;p>=0;p--){
                if(a[i] == a[p]){
                    check = false;
                    break;
                }
            }
            if(check){
                for(int j=0;j<m;j++){
                    if(a[i] == b[j]){
                        cnt++;
                        break;
                    }
                }
            }
            else{
                check = true;
            }

        }
        cout<<cnt<<endl;
    }

}
/*
2
4
2 1 1 3
3
1 2 2
5
1 2 7 4 2
4
2 2 4 4
*/
