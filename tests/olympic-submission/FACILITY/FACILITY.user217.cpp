#include<bits/stdc++.h>
using namespace std;
pair <long long, pair<long long,long long> > C[1000000];
long long T[1000000],t[1000000];
long long maxtien;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long n,K;
	cin>>n>>K;
	for(long long i = 0; i < n ; ++i){
		long long s,d,r;
		cin>>s>>d>>r;
		d += K+s;
		C[i].first = d;
		C[i].second.first=s;
		C[i].second.second=r;
	}
	
	sort(C,C+n);
	maxtien = t[0] = T[0] = C[0].second.second;
	for(long long i = 1; i < n ; ++i){
		int j = i-1;
		while(j>=0&&C[i].second.first < C[j].first){
			--j;
		}
		if(j>=0) T[i] = C[i].second.second + t[j];
		else T[i] = C[i].second.second;
		if(T[i]>maxtien){
			maxtien=T[i];
		}
		t[i] = maxtien;
	}
	cout<<maxtien<<endl;
	
}
