#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, an[1000], bn[1000];
	int t, dem = 0;
	cin >> t;
	while (t--) {
		cin >> a;
		for (int i = 1; i <= a; i++){
			cin >> an[i];
		}
		cin >> b;
		for (int i = 1; i <= b; i++) {
			cin >> bn[i];
		}
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				if (an[i] == bn[j]) {
					dem++;
				}
			}
		}
		cout << dem << endl;
	}
}
