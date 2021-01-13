#include <iostream>
#include <stack>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int dem;
int n;
int gt[8]={0};
int ck[10];
void Try(int k){
    for(int i = 0; i<=9; i++){
        if( ck[i] == 0){
            ck[i] = 1;
            gt[k] = i;
            if( k == 7){
                //cout<<gt[k]<<endl;
                int s1= gt[1]*1000+gt[2]*100+gt[3]*10+gt[4];
                int s2= gt[3]*10000+gt[5]*1000+gt[6]*100+gt[7]*10+gt[4];
                if( s1+s2 == n){
                    dem++;
                }
            }
            else{
                Try(k+1);
            }
            ck[i] = 0;
        }
    }
}

int main()
{
    stack<int>st;
    int t;
    cin>>t;
    int s;
    int x;
    int f;
    while(t--){
        cin>>n;
        int q=n;
        dem = 0;
        memset(ck,0,sizeof(ck));
        while( q!=0 ){
            x = q%10;
            st.push(x);
            q /=10;
        }
        int l=0;
        s = st.size();
        char num[s+1];
        while( !st.empty()){
            num[l++]= st.top()+'0';
            st.pop();
        }
        int f = num[s-1] - '0';
        if( f == 1 || f == 3 || f == 5|| f==7|| f==9){
            cout<<0<<endl;
            continue;
        }
        else{
            Try(1);
            cout<<dem<<endl;
        }
    }
    return 0;
}
