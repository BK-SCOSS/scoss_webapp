#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T ;
for(int k =0;k< T;k++){
    string a, b, op="";
    cin>>a>>b;
    int da=20-a.length();
    for(int i=0;i<da;i++){
        a = "0"+a;
    }
    int db=20-b.length();
    for(int i=0;i<db;i++){
        b = "0"+b;
    }
    // cout<< a<<"  "<<b;
    int c=0,d=0,u=0;
    for(int i=19;i>=0;i--){
        c = d + (int)a[i] + (int)b[i] -96;
        d = c/10;
        u = c%10+48;
        op = (char)u +op;
    }
    int j=0;
    while(op[j]==48) {j++;}
    while(j<20) cout<< op[j++];
    cout<< endl;
}
    return 0;
}