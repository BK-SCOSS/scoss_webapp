#include <bits/stdc++.h>
using namespace std;
int a,b;
unsigned long long tich1, tich2;
unsigned long long dem;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> a;
	for (int i=1;i<=a;i++) {
		dem =0;
		cin >> b;
		tich1=b*(b+1)*(b+2);
		tich2=tich1*tich1;
			for (int j=2;j<=tich1;j++) {
				if (tich2%j==0 && tich1%j!=0) {
					dem++;
				}
			}
		}
		cout << dem << " ";
}
