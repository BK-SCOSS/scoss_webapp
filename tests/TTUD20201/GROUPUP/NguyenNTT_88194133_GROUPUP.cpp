#include<bits/stdc++.h>
using namespace std;
main(){
	int T, n;
	vector<int> a;
	cin>>T;
	while(T--){
		cin>>n;
		a.resize(n);
		for (int i =0;i<n;i++){
			cin>>a[i];
		}
		int minTime=0;
		int currentTime = n;
		while(1){
			int temp = currentTime;
			int t = 0;
			int k = 0;
			int i = 0;
			while (i<currentTime-1){
				a[k] = a[i] + a[i+1];
				t = max(t, a[k]);
				--temp;
				i += 2;
				++k;
			}
			a[k] = (currentTime&1) ? a[currentTime - 1] : a[k];
			currentTime = temp;
			minTime +=t;
			if (currentTime == 1) break;
		}
		cout<<minTime<< endl;
	}
}

