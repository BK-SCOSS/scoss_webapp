#include <bits/stdc++.h>
using namespace std;

int n, T;
int a[100001];
vector<int> result;
deque<int> mem;

int solve(){
	int rs = 0;
	int a, b;
	while(mem.size() > 1){
		vector<int> nho;
		int max_turn = 0;
		while(mem.size() > 1){
			a = mem.front();
			mem.pop_front();
			b = mem.front();
			mem.pop_front();
			max_turn = max(max_turn, a + b);
			nho.push_back(a+b);
		}
		rs += max_turn;
		for(int i = nho.size() - 1; i>=0; i--){
			mem.push_front(nho[i]);
		}
	}
	mem.clear();
	return rs;
}

int main(){
	
	cin >> T;
	for(int i = 0; i<T; i++){
		cin >> n; 
		for(int j = 0; j<n; j++){
			cin >> a[j];
			mem.push_back(a[j]);
		}
		result.push_back(solve());
	}
	
	for(int i = 0; i<T; i++){
		cout << result[i] << "\n";
	}
		
	return 0;
}

