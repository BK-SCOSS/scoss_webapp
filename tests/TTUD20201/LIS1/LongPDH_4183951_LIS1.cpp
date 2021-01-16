#include <iostream>
int t;
int n;
int main () {
    std::cin >> t;

    while(t) {
        std::cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        int result[n];
        int max = 0;
        for(int i = 0; i < n; i++) {
            result[i] = 1;
        }
        result[0] = 1;
        for(int i = 1; i < n ; i++) {
            for(int j = i - 1; j > -1; j--) {
                if(a[i] - a[j] == 1) {
                    result[i] = result[j] + 1;
                    break;
                }
            }
            if(max < result[i])
                max = result[i];
        }

        std::cout << max << "\n";

        t--;
    }
}
