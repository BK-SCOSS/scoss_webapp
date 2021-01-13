#include <bits/stdc++.h>
using namespace std;
int n, arr[9],res,used;
int calculate(){
	if ((arr[1]*1000+arr[2]*100+arr[3]*10+arr[4] + arr[3]*10000 + arr[5]*1000+arr[6]*100+arr[7]*10+arr[4])==n) return 1;
	return 0;
}
void TRY(int k){
	for (int i = 0;i<=9;++i){
		if (i==0){
			if (k==1||k==3) continue;
		}
		if (((used>>i)&1)==0){
			used += 1<<i;
			arr[k] = i;
			if (k==7){
				if (calculate()) {
					++res;
				}
			}
			else {
				TRY(k+1);
			}
			used -= 1<<i;
		}
	}
}
main(){
//	freopen("input.txt","r",stdin);
	int t;
	cin >> t;
	while (t--){
		res = 0;
		used = 0;
		cin >> n;
		TRY(1);
		cout << res << endl;
	}
}
