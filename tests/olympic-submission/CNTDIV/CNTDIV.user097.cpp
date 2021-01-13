#include<iostream>
#define max 100
using namespace std;
int main(){
    long int Q;
    long int arr[max];
    cin>>Q;
    for(int j = 0; j<Q; ++j){
            long int n;
    do{
        cin>>n;
    }while(n<=0);
    long int T = n*(n+1)*(n+2);
    int dem = 0;
    for(int i = 2; i<T; ++i){
        if((T*T%i==0)&&i<T&&(T%i!=0)){
            ++dem;
        }
    }
        arr[j] = dem;
    }
    for(int i = 0; i<Q; ++i){
        cout<<arr[i]<<endl;
    }
    return 0;
}