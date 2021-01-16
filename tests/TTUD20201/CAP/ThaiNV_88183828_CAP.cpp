#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 102
#define MAXM 102

//int a[MAXN], b[MAXM];

int main()
{
    int T; std::cin >> T;
    std::vector<int> T_res;
    while (T--)
    {
        int n, m; 

        std::cin >> n;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }

        std::cin >> m;
        std::vector<long long>b(m);
        for (int i = 0; i < m; ++i)
        {
            std::cin >> b[i];
        }

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        /*for (auto i: a)
            std::cout << i << " ";

        std::cout << "\n";
        for (auto j: b)
            std::cout << j << " ";*/

        std::vector<long long> ab_intersection;
        std::set_intersection(a.begin(), a.end(),
                          b.begin(), b.end(),
                          std::back_inserter(ab_intersection));
        T_res.push_back(ab_intersection.size());
    }

    for (auto i: T_res)
        std::cout << i << "\n";
}