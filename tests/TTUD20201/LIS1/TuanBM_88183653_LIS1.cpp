#include <iostream>
#include <map>
using namespace std;

int a[100005] = {};
int n;
int res = 0;
int t;
map <int, int> arr;


void xuli() {
    for (int i = 0; i < n; i++) {
        arr[a[i]] = 1;
        auto search = arr.find(a[i] - 1);
        if (search != arr.end()) {
            arr[a[i]] = search->second + 1;

        }
        res = max(res, arr[a[i]]);

    }
}
//void xuli() {
//    for (int i = 0; i < n; i++) {
//        arr[a[i]] = 1;
//        auto search = arr.find(a[i] - 1);
//            arr[a[i]] = search->second + 1;
//
//        }
//
//    }
//}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        xuli();
        cout << res << endl;
    }
}
