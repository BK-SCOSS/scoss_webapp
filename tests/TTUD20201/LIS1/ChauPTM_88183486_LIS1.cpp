#include <bits/stdc++.h>

#include <cstring>
using namespace std;

int t, n;
int a[100001];
int F[100001];
int duyet(int i){
	if (F[i]!=-1){
		return F[i];
	}
	int res=1;
	for (int j=0; j<i; j++){
		if (a[j]+1== a[i]){
			res = max(res, 1 + duyet(j));
		}
	}
	F[i]= res;
	return res;
}

int main(){
	cin >>t;
	while (t--){
		cin >>n;
		for (int i=0; i<n; i++){
			cin >>a[i];
			F[i]=-1;
		}
		int res=0;
		for (int i=0; i<n ;i++){
			res= max(res, duyet(i));
		}
		cout <<res;
	}
}
