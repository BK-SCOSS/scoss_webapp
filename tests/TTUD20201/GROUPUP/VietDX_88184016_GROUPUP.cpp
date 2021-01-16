#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int n;
int a[MAX], kq[MAX], sum[MAX], cnt = 1;

int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0, kq = 0;
        int upper = n;
        while (upper >= 0) {
            if (upper == 1) {
            	sum[cnt] = a[0] + a[1];	
				for (int i = 1; i <= cnt; i++) 
					ans += sum[i];
				cout << ans;
				break;
			}
            if (upper % 2 == 0) {
                upper = upper / 2;
                for (int i = 0; i < upper; i++) {
                    a[i] = a[i * 2] + a[i * 2 + 1];
                }
                sum[cnt] = *max_element(a, a + upper);
                cnt++;
            } else {
                upper = upper / 2; 
                for (int i = 0; i < upper; i++) {
                    a[i] = a[i * 2] + a[i * 2 + 1];
                    //cout << a[i] << " ";
                }
                a[upper] = a[upper * 2];
                for (int i = 0; i <= upper; i++)
                sum[cnt] = *max_element(a, a + upper + 1);
                cnt++;
        	}	
        }
    }
}


