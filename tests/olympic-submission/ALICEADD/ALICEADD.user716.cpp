#include<iostream>
#include<string>
#include<vector>

#define bigboi 1000000000000000ULL

int main() {
    int n;
    std::vector<std::string> res;
    std::cin >> n;
    while(n--) {
        uint64_t a2, a1, b1, b2, c1, c2, input;
        std::cin >> input;
        a1 = input % bigboi;
        a2 = input / bigboi;
        std::cin >> input;
        b1 = input % bigboi;
        b2 = input / bigboi;
        c1 = a1 + b1;
        c2 = a2 + b2;
        c2 += c1 / bigboi;
        c1 %= bigboi; 
        std::string r = "";
        std::string c1str = std::to_string(c1);
        if(c2 > 0) {
            r += std::to_string(c2);
            for(int i = 0; i < 15 - c1str.size(); i++) {
                r += "0";
            }
        } 
        r += c1str;
        res.push_back(r);
    }
    for(auto r : res) {
        std::cout << r << '\n';
    }

    return 0;
}