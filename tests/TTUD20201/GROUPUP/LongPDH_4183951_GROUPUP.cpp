#include <iostream>
#include <deque>
#include <vector>
int t;
int n;
int main() {
    std::cin >> t;

    while(t) {
        std::cin >> n;

        std::vector<int> vec;
        for(int i = 0; i < n; i++) {
            int a;
            std::cin >> a;
            vec.push_back(a);
        }

        int result = 0;
        while(vec.size() != 1) {
            int max = 0;
            if(vec.size() % 2 == 0) {
                std::vector<int> temp(vec.size() / 2);
                for(int i = 0; i < temp.size(); i++) {
                    temp[i] = vec[i * 2] + vec[i * 2 + 1];

                    if(max < temp[i])
                        max = temp[i];
                }
                vec = temp;
            }
            else {
                std::vector<int> temp(vec.size() / 2 + 1);
                for(int i = 0; i < temp.size() - 1; i++) {
                    temp[i] = vec[i * 2] + vec[i * 2 + 1];
                    if(max < temp[i])
                        max = temp[i];
                }
                temp.back() = vec.back();
                vec = temp;
            }
            result += max;
        }
        std::cout << result << "\n";

        t--;
    }
}
