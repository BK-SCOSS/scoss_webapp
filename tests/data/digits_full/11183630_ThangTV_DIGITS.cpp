#include <bits/stdc++.h>
using namespace std;
int t,n;
int dem ;
bool check[10];
int cn=9;
char a[9];
void solution(){
    string st ="";
    string rt ="";
    for(int i=1;i<=4;i++)
        rt = rt+ a[i];
    for(int i=5;i<=9;i++)
        st= st+a[i];
    int d1,d2;
    d1 = atoi(st.c_str());
    d2 = atoi(rt.c_str());
    if(d1+d2==n) dem++;
}
void Try(int k){
    if(k==5) {
        a[k] = a[3];
        Try(k+1);
    }
    else {
        if (k == 9) {
            a[k] = a[4];
            solution();
        }
        else {
            for (int i = 0; i <= 9; i++) {
                if (i == 0 && k == 1) continue;
                if(i==0 && k == 3) continue;
                if (!check[i]) {
                    a[k] = (char) (i + 48);
                    check[i] = true;
                    Try(k + 1);
                    check[i] =false;
                }
            }
        }
    }
}
int main() {
    cin>>t;
    for(int i=1;i<=t;i++){
       cin>>n;
       dem =0;
       Try(1);
       cout<<dem<<endl;
    }
}
/*
5
17868
29119
49862
78952
1000002*/
