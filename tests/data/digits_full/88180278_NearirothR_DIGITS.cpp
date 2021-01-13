#include<bits/stdc++.h>
using namespace std;
int n, a[4], d[5], res;

bool check(){
	
	int t = a[1] *1000 + a[2]*100+ a[3]*10+ a[4] + a[3]*10000 +a[5]*1000+a[6]*100+a[7]*10+a[4];
	return t=n;
}

void Try(int x){
	if (x==4) {
		if(check()) ++res;
		return;
	}
	for (int i=1; i<=5;i++){
		if(!d[i]){
			d[i]=1;
			a[x]=i;
			Try(x+1);
			d[i]=0;
		}
		
	}
	
}
int main(){
	cin >> n;
	Try(1);
	cout << res;
	return 0;
}
