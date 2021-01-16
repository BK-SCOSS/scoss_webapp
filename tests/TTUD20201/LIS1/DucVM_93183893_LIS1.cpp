#include <bits/stdc++.h>
using namespace std;

int T;
int a[100001];
int mem[100001];
vector<int> result;

int lis(int i) {
	if (mem[i] != -1) {
		return mem[i];
	}
	int res = 1;
	for (int j = 0; j < i; j++) { 
		if (a[j] + 1 == a[i]) {
			res = max(res, 1 + lis(j));
		}
	}
	mem[i] = res;
	return res;
}


int main(){
	memset(mem, -1, sizeof(mem));
	int n;
	cin >> T;
	for(int i = 0; i<T; i++){
		cin >> n;
		for(int j = 0; j<n; j++){
			cin >> a[j];
		}
		int rs_max = 0;
		for(int j = 0; j<n; j++){
			rs_max = max(rs_max, lis(j));
		}
		result.push_back(rs_max);
		memset(mem, -1, sizeof(mem));
	}
	
	for(int i = 0; i<T; i++){
		cout << result[i] << "\n";
	}

	return 0;
}

