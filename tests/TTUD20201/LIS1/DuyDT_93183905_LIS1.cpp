#include <bits/stdc++.h>

using namespace std;

vector<int> d;
vector<int> save;

int Try(int n){
	if(n <= 0) return 0;
	if(save[n] > 0) return save[n];
	int t;
	for(t = n - 1; t > 0; t--){
		if(d[n] - d[t] == 1) break;
	}
	if(t > 0) {
		save[n] = 1 + Try(t);
	}else save[n] = 1;
	return save[n];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
    	int n;
		cin >> n;
		d.push_back(0);
		save.resize(n + 1, 0);
		int tmp;
		for(int i = 0; i < n; i++){
			cin >> tmp;
			d.push_back(tmp);
		}
		int res = 0;
		for(int i = n; i > 0; i--){
			int tt = Try(i);
			if(tt > res) res = tt;
		}
		cout << res << endl;
		d.clear();
		save.clear();
	}
	return 0;
}
