#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	int cases;
	cin >> cases;
	vector<int> all_res;
	
	for (int c = 0; c < cases; c++){
		map<int, int> m;
		int n1;
		cin >> n1;
		int* a = new int[n1];
		for (int i = 0; i < n1; i++){
			cin >> a[i];
			if (m.find(a[i]) == m.end()) m[a[i]]++;
		}
		
		int n2;
		cin >> n2;
		int* b = new int[n2];
		for (int i = 0; i < n2; i++){
			cin >> b[i];
			m[b[i]]++;
		}
		
		int res = 0;
		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++){
			//cout << it->first << " " << it->second << endl;
			if (it->second > 1 && it->first > 0) res++;
		}
		all_res.push_back(res);
	}
	
	for (int i = 0; i < all_res.size(); i++){
		cout << all_res[i] << endl;
	}
}
