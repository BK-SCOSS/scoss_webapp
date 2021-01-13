#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int p[7] = {10010, 1000, 1000, 100, 100, 10, 2};

int n, a[7], sum;
long long dem;
bool visited[10];

void branch(int k) {
	for(int i = 0; i < 10; i++) {
		if(k == 0 && i == 0) continue;
		if(k == 1 && i == 0) continue;
		if(!visited[i]) {
			a[k] = i;
			visited[i] = true;
			sum -= p[k]*a[k];
			
			if(k == 6) {
				if (sum == 0) dem++;
			}
			else if (sum >= 0) branch(k+1);
			
			sum += p[k] * a[k];
			visited[i] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		if(n > 110000 || (n % 2 == 1)) {
			cout << 0 << endl;
			continue;
		}
		
		for(int i = 0; i < 10; i++) visited[i] = false;
		dem = 0;
		sum = n;
		branch(0);
		cout << dem << endl;			
	}
	return 0;
}
