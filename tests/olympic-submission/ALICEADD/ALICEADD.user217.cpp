#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	for( int i = 0; i < T; ++i){
		unsigned long long a,b;
		cin>>a>>b;
		unsigned long long A = a%10;
		a /= 10;
		unsigned long long B = b%10;
		b /= 10;
		unsigned long long c = a+b + (A+B)/10;
		if(c>0) cout<<c;
		cout<<(A+B)%10<<endl;
	}
}
