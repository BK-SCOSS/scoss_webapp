#include<iostream>

using namespace std;

void output(int a[], int b[], int t){
    for(int i = 0; i < t; i++)
        cout<<a[i]+b[i]<<endl;
}

void input(int a[], int b[], int t){
    for(int i = 0; i < t; i++){
        do
            cin>>a[i]>>b[i];
        while(a < 0 || b < 0);
    }
}

int main(){
    int a[10], b[10];
    int T;
    do
        cin>>T;
    while(T > 10);

    input(a,b,T);
    output(a,b,T);
}