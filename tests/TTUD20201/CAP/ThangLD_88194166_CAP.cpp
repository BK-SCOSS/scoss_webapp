#include <bits/stdc++.h>
using namespace std;
main(){
   // freopen("bai1.txt","r",stdin);
    int t,n,m;
//    ios_base::sync_with_stdio(0);
 //   cin.tie(0);
    cin >> t;
    int a[100];
    vector<int> b;
    int tmp;
    while (t--){
    	int count = 0;
    	cin >> n;
	for (int i = 0;i<n;++i) cin >> a[i];
	cin >> m;
	b.resize(m);
	for (int i = 0;i<m;++i){
		cin >> tmp;
		for (int j = 0; j<n;++j){
			if (tmp == a[j]){
				++count;
				break;
			}
		}
	}
    	cout << count << endl;
    }
}
