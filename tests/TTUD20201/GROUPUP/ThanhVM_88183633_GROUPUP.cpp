#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int n;
int a[100005];
int main()
{
    int t;
    cin >> t;
    while(t--){
        vector<int> vt;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            vt.push_back(a[i]);
        }
        int res = 0;

        while(vt.size() != 1){
            vector<int> new_vt;
            int tmp;
            for(unsigned int i = 0; i < vt.size(); i = i + 2){
                tmp = vt[i] + vt[i + 1];
                new_vt.push_back(tmp);
                if (i + 3 == vt.size()){
                    new_vt.push_back(vt[i+2]);
                    break;
                }
            }

            res += *max_element(new_vt.begin(), new_vt.end());
            vt = new_vt;
        }

        cout << res << endl;
    }
    return 0;
}
