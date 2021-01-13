#include <bits/stdc++.h>
using namespace std;
//int H, U, S, T, O, I, C;
int hust[7];
int N[51], test;
int digit[10]={0,1,2,3,4,5,6,7,8,9};
int mark[10]{};

int main(){
    cin>>test;
    for(int t=0; t<test; t++){
        cin>>N[t];
    }
    for(int t1=0; t1<test; t1++){
        for(int chu=0; chu<7; chu++){
            for(int so=0; so<10; so++){
                if(mark[so]!=-1){
                    hust[chu] = digit[so];
                    mark[so]=-1;
                }
                
            }
        }
    }
    return 0;
}
