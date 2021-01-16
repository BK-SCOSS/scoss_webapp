#include <bits/stdc++.h>
using namespace std;

int T, n, m;
int *a, *b;
queue<int> result;
//vector<int> found;


int main() {
//	ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    cin >> T;
    while(T--) {
    	//read a
    	cin >> n;
    	a = new int[n];
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
		}
		
		//read b
		cin >> m;
    	b = new int[m];
    	for (int i = 0; i < m; i++) {
    		cin >> b[i];
		}
    	int cnt = 0;
    	//process
    	for (int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
    			if(a[i] == b[j]) {
    				cnt++;
    				break;
				}
			}
    	}
    	result.push(cnt);
    	delete[] a;
    	delete[] b;
	}
    
    while(!result.empty()) {
    	cout << result.front() << endl;
    	result.pop();
	}

	return 0;
}
