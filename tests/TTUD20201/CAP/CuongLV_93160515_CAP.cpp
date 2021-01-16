#include<iostream>
using namespace std;
#define MAX_N 100001
int n, m;
int N[MAX_N], M[MAX_N];
int dem = 0;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> N[i];
	}
	cin >> m;
	for (int j = 1; j <= m; j++) {
		cin >> M[j];
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		input();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (N[i] == M[j]) {
					dem = dem + 1;
					break;
				}
			}
		}
		cout << dem << "\n";
		dem = 0;
	}
}