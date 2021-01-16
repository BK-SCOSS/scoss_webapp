#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--){
		int n;
		int m;
		int res = 0;
		int cnt = 0;
		vector <int> a, b;
		cin >> n;
		for (int i = 0; i < n; i++){
			int temp;
			cin >> temp;
			if (a.size() == 1) a.push_back(temp);
			else {
				for (int j = 0; j < a.size(); j++){
					if (a[j] == temp) a.erase(a.begin() + j);
				}
				a.push_back(temp);
			}
		}
		cin >> m;
		for (int i = 0; i < m; i++){
			int temp2;
			cin >> temp2;
			b.push_back(temp2);
		}
		// xu ly

		for (int i = 0; i < a.size(); i++){
			for (int j = 0; j < m; j++){
				if (a[i] == b[j]) {
				res++;
				break;
			}
		}
    }
    cout << res;
}
}

