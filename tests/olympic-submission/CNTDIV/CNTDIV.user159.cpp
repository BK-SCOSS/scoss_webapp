#include<bits/stdc++.h>
using namespace std;
int main(){
int Q;
cin>>Q;
for(int i=0;i<Q;i++){
long long n;
cin>>n;
long long t=n*(n+1)*(n+2);
long long s=t*t;
long long dem=0;
for(i=2;i<t;i++){
if(s%i==0&&t%i){
dem++;
}
}
cout<<dem<<endl;
}
}
