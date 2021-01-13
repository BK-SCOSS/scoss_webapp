#include<bits/stdc++.h>
using namespace std;
int n;
int val[10];
int rs;
int target;
int sum(){
    return val[1]*10010 + val[2] * 1000 + val[3] * 1000+ val[4] * 100 +val[5]*100 + val[6]*10+val[7] *2;
}
bool check(int a){
    for(int i =1;i<=7;i++){
        if(val[i] == a ) return false;

    }
    return true;
}
void dequy(int k){
    if(k==8){
        if(target == sum() && val[1]!=0 && val[2]!=0){

            rs++;
        }
    }else {
        for(int i=0;i<=9;i++){
            if(check(i)){
            val[k] = i;
            dequy(k+1);
            val[k] = -1;
        }
      }

    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >>n;
    for(int i=1;i<=7;i++){
        val[i] =-1;
    }
    for (int i =0; i<n;i++){
        rs = 0;
        cin >> target;
        if(target %2 ==1 || target > 200000){
            cout << 0 <<endl;
        }
        else{

        dequy(1);
        cout << rs <<endl;
        }
    }

}
