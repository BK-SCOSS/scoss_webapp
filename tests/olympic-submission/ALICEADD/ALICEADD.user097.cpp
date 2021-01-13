#include<iostream>
#define max 100
using namespace std;
int main(){
    int n;
    do{
        cin>>n;
    }while(n<0||n>10);
    long int a[max][2];
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<2; ++j){
            cin>>a[i][j];
        }
    }
    long int arr[max] = {0};
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<2; ++j){
            arr[i]+=a[i][j];
        }
        cout<<arr[i]<<endl;
    }
    return 0;
}