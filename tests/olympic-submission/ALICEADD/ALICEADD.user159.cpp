#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
unsigned long long a[11],b[11],s[11];
cin>>T;
for(int i=0;i<T;i++){
cin>>a[i]>>b[i];
s[i]=a[i]+b[i];
}
for(int i=0;i<T;i++){
cout<<s[i]<<endl;
}
}
