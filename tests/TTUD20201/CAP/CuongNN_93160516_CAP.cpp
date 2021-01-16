#include<bits/stdc++.h>

int t, n, m;
int a[200], b[200];
int count = 0;

int main() {
    std::cin >> t;
    for(int i = 1; i <= t; i++) {
        std::cin >> n;
        for(int j = 1; j <= n; j++) {
            std::cin >> a[j];
        }
        std::cin >> m;
        for(int j = 1; j <= m; j++) {
            std::cin >> b[j];
            for(int k = 1; k <= n; k++) {
                if(a[k] == b[j]) {
                    count++; break;
                }
            }
        }
        // std::sort(a+1, a+n+1);
        // std::sort(b+1, b+m+1);
        // for(auto x : a) {std::cout << x;}
        // int ia = 1, ib = 1;
        // count = 0;
        // while(ia <= n && ib <= m) {
        //     int min = 0;
        //     if(a[ia] == b[ib]) {
        //         int mina = 0, minb = 0;
        //         do{
        //             mina++;
        //             ia++;
        //         }
        //         while(ia <= n && a[ia] <= a[ia-1]);
        //         do {
        //             minb++;
        //             ib++;
        //         }
        //         while(ib <= m && b[ib] <= b[ib-1]);
        //         // ib++;
        //         // ia++;
        //         min = std::min(mina, minb);
        //         count += min;
        //     } else if(a[ia] > b[ib]){
        //         ib++;
        //     } else {
        //         ia++;
        //     }
        // }
        // int minn;
        // int maxx;
        // if(a[1] > b[1]) {
            
        // }
        // int a = ((a[1] > b[1]) ? a : b);
        // int b = ((a[n] < b[m]) ? a : b);

        std::cout << count;
    }
    return 0;
}