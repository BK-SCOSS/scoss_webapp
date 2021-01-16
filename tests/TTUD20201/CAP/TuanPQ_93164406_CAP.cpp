#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m, input, cnt = 0;
        vector<int> a,b;
        cin >> n;
        for(int i=0; i<n;i ++) {
            cin >> input;
            a.push_back(input);
        }
        cin >> m;
        for(int i=0; i<m;i ++) {
            cin >> input;
            b.push_back(input);
        }

        for (int i=0;i<a.size();i++) {
            for (int j=0; j<b.size();j++) {
                if (a[i] == b[j]) {
                    cnt++;
                    b.erase(b.begin()+j,b.begin()+j+1 );
                }
            }

        }
        cout << cnt;
    }
	return 0;
}
