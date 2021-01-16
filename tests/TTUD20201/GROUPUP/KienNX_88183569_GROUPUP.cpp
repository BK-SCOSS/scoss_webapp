//phao hoa gi do
#include<bits/stdc++.h>
using namespace std;
int n;
vector <int> a, b;
int main(){
	int T;
	cin >> T;
	while (T--){

			//nhap du lieu
		cin >> n;
		for (int i = 0; i < n; i++){
			int temp;
			cin >> temp;
			b.push_back(temp);
		}
		for (int i = 0; i < b.size(); i++){
			a.push_back(b[i]);
		}
	// xu ly
	int res = 0;
	int time = 0;

	while (a.size()!=1){
		if (a.size()%2 == 0){
		for (int i = 0; i < a.size()-1; i++){
			a[i] += a[i+1];
			a.erase(a.begin()+(i+1));
			time = max(time, a[i]);
		}
	}
		else{
			for (int i = 0; i < a.size()- 2; i++){
			a[i] += a[i+1];
			a.erase(a.begin()+(i+1));
			time = max(time, a[i]);
		}
		}
		res += time;
	}
	cout << res;
	}
}
