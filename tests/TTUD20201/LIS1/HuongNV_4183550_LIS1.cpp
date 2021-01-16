#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int MIN_i=0;
        int dem=1;
        for(int i=1;i<n;i++){
            if(arr[i]<arr[MIN_i]) MIN_i=i;
        }
        for(int i=MIN_i+1;i<n;i++){
            if(arr[i]==(arr[MIN_i]+1)){
                dem++;
                MIN_i=i;
            }

        }
        cout<<dem;
    }
   return 0;
}
