#include <bits/stdc++.h>
using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int m;
		cin >> m;
		int arr[m];
		vector<int> temp;
		for (int i = 0; i < m; i++) {
			cin >> arr[i];
		}
		int numGroup = m;
		int maxTime = 0, sumTime = 0;
		while (numGroup > 1) {
			if (numGroup % 2 == 0) {
				for (int i = 0; i < numGroup; i = i + 2) {
					temp.push_back(arr[i] + arr[i + 1]);
					maxTime = max(maxTime, arr[i] + arr[i + 1]);
				}
				numGroup = numGroup / 2;
			} else {
				for (int i = 0; i < numGroup - 1; i = i + 2) {
					temp.push_back(arr[i] + arr[i + 1]);
					maxTime = max(maxTime, arr[i] + arr[i + 1]);
				}
				maxTime = max(maxTime, arr[numGroup - 1]);
				temp.push_back(arr[numGroup - 1]);
				numGroup = numGroup / 2 + 1;
			}
//			memset(arr, 0, sizeof(arr));
			for (int i = 0; i < numGroup; i++) {
				arr[numGroup - 1 - i] = temp.back();
				temp.pop_back();
			}
			sumTime += maxTime;
		}
		cout << sumTime << endl;
	}
	return 0;
}
