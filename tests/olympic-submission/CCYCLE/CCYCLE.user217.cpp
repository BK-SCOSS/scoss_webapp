#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
long long dem=0;
long long n,L,s,t;
void Try(long long s, long long l){
	if(l>L) return;
	if(l==L&&s==t){
		++dem;
		dem %= P;
		return;
	}
	if(s%3==1){
		Try(s+1,l+1);
		Try(s+2,l+1);
		if(s==1) Try(3*n,l+1);
		else Try(s-1,l+1);
	}
	else{
		if(s%3==2) Try(s-1,l+1);
		else{
			Try(s-2,l+1);
			Try((s+1)%n,l+1);
		}
	}
}
int main(){
	cin>>n>>L>>s>>t;
	Try(s,0);
	cout<<dem<<endl;
}
