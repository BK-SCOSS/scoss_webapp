#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
    int T; std::cin >> T;
    std::vector<int> time;

    while (T--)
    {
        int n; std::cin >> n;
        int nlog = std::log2(n);

        std::vector<int> a;
        for (int i = 0; i < n; ++i)
        {
            int temp; std::cin >> temp;
            a.push_back(temp);
        }

        std::vector<int> b;
        int total_time = 0;
        
        for (int i = 0; i <= nlog; ++i)
        {
            int _n = a.size();
            if (_n < 2)
                break;

            if (_n % 2 == 0)
            {
                for (int i = 1; i < _n; i += 2)
                {
                    b.push_back(a[i - 1] + a[i]);
                }
            }
            else
            {
                for (int i = 1; i < _n - 1; i += 2)
                {
                    b.push_back(a[i - 1] + a[i]);
                }
                b.push_back(a[_n - 1]);
            }

            a.erase(a.begin(), a.end());

            total_time += *std::max_element(b.begin(), b.end());

            std::copy(b.begin(), b.end(), std::back_inserter(a));
            b.erase(b.begin(), b.end());            
        }    

        time.push_back(total_time);
    }

    for (auto i: time)
        std::cout << i << "\n";
}