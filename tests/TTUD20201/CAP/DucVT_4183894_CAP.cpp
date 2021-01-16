#include <bits/stdc++.h>
using namespace std;
vector<int> kq;
int main(){
	int t,n,m;
	cin >> t;
	while(t>0){
		cin >> n;
		int a[n]; set<int> A;
//		for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) {
		int tmp; cin >> tmp;
		A.insert(tmp);
	}
//	for(int temp: A) cout << temp << " ";
//	cout << endl;
		cin >> m;
		int b[m]; set<int> B;
//		for(int i=0;i<m;i++) cin >> b[i];
		
		for(int i=0;i<m;i++) {
		int tmp; cin >> tmp;
		B.insert(tmp);
	}
//		for(int temp: B) cout << temp << " ";
//		cout << endl;
//	set<int> rs;
	long long rs=0;
	for(int tmp1: A){
		for(int tmp2: B){
			if(tmp1==tmp2) rs++;
		}
	}
	kq.push_back(rs);
//	cout << rs;
		t--;
	}
	for(int temp : kq) cout << temp << endl;
}
