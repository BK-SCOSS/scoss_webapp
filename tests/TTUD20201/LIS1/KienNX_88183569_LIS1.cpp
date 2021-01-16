#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int best = 0;
int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
				while (T--){
				cin >> n;
				for (int i = 0; i < n; i++){
					cin >> a[i];
				}

				//xu ly
				int currValue;
				for (int i = 0; i < n-1; i++){
						currValue = a[i];
						int dem = 1;
					for (int j = i+1; j < n; j++){
						if (a[j] == currValue+1){
							dem++;
							currValue = a[j];
						}
					} // het for 2
					best = max(dem,best);
				}
				cout << best;
			}
}
