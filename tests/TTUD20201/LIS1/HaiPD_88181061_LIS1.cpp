#include<bits/stdc++.h>
#include<stack>
#include<iostream>
using namespace std;
int a [1000005];
long mem [1000005];
int lis( int i) {
if (mem[i] != -1) {
return mem[i];
}
int res = 1;
for ( int j = 0; j < i; j++) {
if (a[j]+1 ==a[i]) {
res = max(res , 1 + lis(j));
}
}
mem [i] = res;
return res;
}
int main(){
    int t;
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        long long n;
    cin>>n;
    memset (mem , -1, sizeof ( mem ));
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    lis(n-1);
    long mx = 0;
for ( int i = 0; i < n; i++) {
mx = max(mx , mem[i]);
}
printf ("%d\n", mx );
    }
}
