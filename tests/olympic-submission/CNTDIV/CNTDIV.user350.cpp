#include<iostream>
using namespace std;
int main(){
    int Q,N;
    long long int T;
    cin>>Q;
    for(int i=0;i<Q;i++){
        cin>>N;
        int count=0;
        T=N*(N+1)*(N+2);
        for(int j=5;j<T;j++){
            if((T*T)%j==0&&T%j!=0)
               count++;
        }
        cout<<count<<endl;
    }
}