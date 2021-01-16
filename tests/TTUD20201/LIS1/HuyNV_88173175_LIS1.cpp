#include <bits/stdc++.h>
using namespace std;

int T, n;
int *a;
int *mark;

queue<int> result;

deque<int> subSequence;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    while(T--) {
    	cin >> n;
    	a = new int[n];
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
		}
		mark = new int[n];
		memset(mark, 0, sizeof(mark));

		int curr = 0;
		int maxSub = 0;
		
		for (int i = 0; i < n - 1; i++) {
			if(mark[i] == 1) continue;
			mark[i] = 1;
			subSequence.clear();
			subSequence.push_back(a[i]);
			curr = a[i];
			
			
    		for (int j = i + 1; j < n; j++) {
    			if(mark[j] == 1) continue;
    			if(a[j] - curr == 1) {
    				subSequence.push_back(a[j]);
    				curr = a[j];
    				mark[j] = 1;
				}
			}
			if(subSequence.size() > maxSub) {
				maxSub = subSequence.size();
			}
		}
		result.push(maxSub);
		delete[] a;
		delete[] mark;
	}
	
	while(!result.empty()) {
    	cout << result.front() << endl;
    	result.pop();
	}
	
	return 0;
}
