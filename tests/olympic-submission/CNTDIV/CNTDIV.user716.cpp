#include<iostream>
#include<vector>

int main() {
    std::vector<uint64_t> res;
    uint64_t c, n;
    std::cin >> c;
    while(c--) {
        std::cin >> n;
        if(n==0 ) {
            res.push_back(0);
        } else {
            uint64_t r = 0;
            uint64_t t = n * (n+1) * (n+2);
            uint64_t t2 = t * t;
            for(int i = 2; i < t; i++) {
                if(t2%i == 0 && t%i != 0) {
                    r++;
                }
            }
            res.push_back(r);
        }

    }
    for(auto r : res) {
        std::cout << r << '\n';
    }

    return 0;
}