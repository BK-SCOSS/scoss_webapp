#include<bits/stdc++.h>
using namespace std;

const int MAX = 1005;

int n;
int a[MAX], kq[MAX];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            kq[i] = 1;
    	}
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (a[i] == a[j] + 1) {
                    kq[i] = max(kq[j] + 1, kq[i]);
            	}
            }
        }
        cout << *max_element(kq + 1, kq + n + 1) << endl;
        for (int i = 1; i <= n; i++)
        	kq[i] = 0;
    }
	return 0;
}
