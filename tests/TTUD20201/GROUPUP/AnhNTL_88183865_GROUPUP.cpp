#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int T;
int n;
int a[MAX];
int cnt;
int rs;

int main() {
    cin >> T;
    for(int t = 0; t < T; t++) {
        for(int i = 0; i < MAX; i++) {
            a[i] = 0;
        }
        rs = 0;

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

       	while (n>1) {
       		cnt = 0;
       		int tmp=0;
       		if(n%2 == 0) {
       			int i=0;
       			while(i<n) {
       				a[cnt] = a[i] + a[i+1];
       				i+=2; cnt++;
				}
				for(int i=0; i<cnt; i++) {
					tmp = max(tmp, a[i]);
				}
				rs += tmp;
				n = n/2;
			}
			else if(n%2 != 0) {
				int i=0;
				while(i<n-1) {
					a[cnt] = a[i] + a[i+1];
					i+=2; cnt++;
				}
				a[cnt] = a[n-1];
				for(int i=0; i<cnt; i++) {
					tmp = max(tmp, a[i]);
				}
				rs += tmp;
				n = n/2+1;
			}
		}
       	
        cout << rs << endl; 
    }
}
