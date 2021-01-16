#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    set<int> a;
    set<int> b;
    int t, n, m, k, num;
    cin >> t;
    while(t--) {
        num = 0;
        cin >> n;
        while(n--) {
            cin >> k;
            if(a.count(k)==0) a.insert(k);
        }
        cin >> m;
        while(m--) {
            cin >> k;
            if(b.count(k)==0){
                b.insert(k);
                if(a.count(k)) num++;
            }
        }
        cout << num << endl;
        a.clear();
        b.clear();
    }
}
