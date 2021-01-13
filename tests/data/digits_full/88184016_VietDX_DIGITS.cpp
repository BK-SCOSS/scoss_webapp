#include<bits/stdc++.h>
using namespace std;

int n;
int a[10];
int cnt = 0;
bool mark[15];

bool check(int k,int i) {
	if (mark[i] == true) return false;
	if (a[k] != -1) return false;
	if (a[1] == 0) return false;
	if (a[3] == 0) return false;
	return true;
}

void TRY(int k) {
	for (int i = 0; i < 10; i++) {
		if (check(k,i)) {
		//if (mark[i] == 1) continue;
		//if (a[k] != -1) continue;
		a[k] = i;
		mark[i] = true;
		if (k == 7) {
			if ((1000 * a[1] + 100 * a[2] + 10 * a[3] + a[4] + 10000 * a[3] + 1000 * a[5] + 100 * a[6] + 10 * a[7] + a[4]) == n) 
				cnt++;
		}
		else {
			TRY(k + 1);
		}
		mark[i] = false;
		a[k] = -1;
		}
	}
}


int main() {
	int nTest;
	cin >> nTest;
	while (nTest--) {
		cin >> n;
		for (int i = 0; i < 15; i++)
			mark[i] = false;
		for (int i = 1; i < 8; i++)
			a[i] = -1;
		TRY(1);
		cout << cnt << endl;
		cnt = 0;	
	}
	return 0;
}

