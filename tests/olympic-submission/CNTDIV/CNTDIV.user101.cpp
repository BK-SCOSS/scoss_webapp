#include<iostream>
using namespace std;
int procedure(int x){
    int t=x*(x+1)*(x+2);
    int m=t*t;
    int k=0;
    //cout<<t<<endl;
    for(int i=2;i<t;i++){
        if(m%i==0&&t%i!=0) k++;
    }
    return k;
}

int main(){
    int q;
    cin>>q;
    int a[q];
    for(int i=0;i<q;i++){
        cin>>a[i];
    }
 //   cout<<procedure(2);
    for(int i=0;i<q;i++){
        cout<<procedure(a[i])<<endl;
    }
    return 0;
}
