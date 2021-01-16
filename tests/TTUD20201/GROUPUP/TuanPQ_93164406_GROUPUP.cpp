#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, input, res=0;
        vector<int> a, b;
        cin >> n;
        for(int i=0; i<n;i++) {
            cin >> input;
            a.push_back(input);
        }

        while (a.size()>1) {
                b.clear();

                for(int i=0; i<a.size();i++) {
                    cout << a[i] << " ";
                }

            int maxSum = INT_MIN;
            int temp;
            for(int i=0; i<a.size(); i+=2) {
                temp = a[i] + a[i+1];
                b.push_back(temp);
                if (maxSum < temp) maxSum = temp;
            }
            if (a.size()/2==1) b.push_back(a[a.size()-1]);
            res+=maxSum;


            a.erase(a.begin(), a.end());
            for(int i=0; i<b.size();i++) {
                a.push_back(b[i]);
            }

            //cout << "res:" << res << endl;


        }

        //cout << res;
    }
	return 0;
}
