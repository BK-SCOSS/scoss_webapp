#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, input;
        vector<int> a, b;
        cin >> n;
        for(int i=0; i<n;i++) {
            cin >> input;
            a.push_back(input);
            b.push_back(1);
        }


        for(int i=0; i<n;i++) {
            for (int j=i+1; j<n; j++) {
                if(a[j] == a[i]+b[i]) b[i]++;

            }
        }

        int res = b[0];
        for(int i=1; i<n;i++) {
            if (b[i] > res) res = b[i];
        }

        cout << res;
    }
	return 0;
}
