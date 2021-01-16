#include<bits/stdc++.h>
using namespace std;

int T,n;
long long a[100005],b[100005],c[100005],ans,result;

int groupup(int m){

	ans=0;
	if(m<=1) return result;
	for(int i=1;i<m;i=i+2){
		int k=(i+1)/2;
		a[k]=a[i]+a[i+1];
		if(a[k]>ans) ans=a[k];

	}
	int k=(m/2)+1;
	if((m%2) and(m>1) ){
		a[k]=a[m];
		if(a[k]>ans) ans=a[k];
	}

	result+=ans;

	groupup(m/2);
}


int main(){
	cin >> T;
	
	for(int k=1;k<=T;k++){
		result=0;
		ans=0;
		cin >> n ;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}

		groupup(n);

		cout << result << endl;
	}
	
  return 0;
}
