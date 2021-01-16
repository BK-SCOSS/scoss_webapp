#include <bits/stdc++.h>

using namespace std;

int group(vector<int> a){
	vector<int> temp = a;
	vector<int> all_res;
	while (temp.size() >= 1){
		vector<int> new_temp;
		int n = temp.size();
		int time = INT_MIN;
		//cout << "size " << n << " ";
		for (int i = 0; i < n; i+=2){
			if (i == n - 1) {
				time = max(time, temp[i]);
				new_temp.push_back(temp[i]);
			}
			else{
				new_temp.push_back(temp[i] + temp[i + 1]);
				time = max(time, temp[i] + temp[i + 1]);
			}
		}
		temp = new_temp;
		all_res.push_back(time);
		if(new_temp.size()== 1) break;
	}
	int res = 0;
	for (int i = 0; i < all_res.size(); i++){
		res += all_res[i];
	}
	return res;
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	for (int c = 0; c < cases; c++){
		int n;
		scanf("%d", &n);
		vector<int> a;
		for (int i = 0; i < n; i++){
			int t;
			scanf("%d", &t);
			a.push_back(t);
		}
		
		int res = group(a);
		
		cout << res << endl;
	}
}
