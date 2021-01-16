#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[100000];
int n,tim,maxi,c;
void doit( int cap){
    if(cap<n*2){
    c=cap/2;
    maxi =0;
    for(int i=0; i<n; i+=cap){
        a[i]+=a[i+c];
        maxi= max(maxi, a[i]);
    }
    tim+=maxi;
    doit(cap*2);
    }
}
int main(){
    int cas;
    cin >> cas;
    while(cas--){
        int tmp;
        tim=0;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
    doit(2);
    cout << tim;
    }
}