#include <iostream>
#include <algorithm>
int t;
int n, m;

bool sortfunc(int a, int b) {
    if(a < b) return true;
    return false;
}

int main() {
    std::cin >> t;

    while(t) {
        std::cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::cin >> m;
        int b[m];
        for(int i = 0; i < m; i++) {
            std::cin >> b[i];
        }

        std::sort(a, a + n, sortfunc);
        std::sort(b, b + m, sortfunc);

        int count = 0;
        int i = 0;
        int j = 0;
        while(i < n && j < m) {
            if(a[i] == b[j]) {
                count++;
                int t = i;
                while(a[t] == a[i]) {
                    i++;
                }
                t = j;
                while(b[t] == b[j]) {
                    j++;
                }
            }
            else if (a[i] < b[j]) {
                i++;
            }
            else if (a[i] > b[j]) {
                j++;
            }
        }
        std::cout << count << "\n";
        t--;
    }
}
