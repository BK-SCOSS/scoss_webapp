#include<bits/stdc++.h>
using namespace std;

int main(){
	long long Q;
	cin>>Q;
	for(int i = 0; i < Q ; ++i){
		long long N;
		cin>>N;
		long long T = N*(N+1)*(N+2);
		long long dem = 0;
		for(long long j = 3; j < T; ++j){
			long long tmp = T%j;
			tmp *= tmp;
			if(tmp&&tmp%j==0) ++dem;
		}
		cout<<dem<<endl;
	}
}
