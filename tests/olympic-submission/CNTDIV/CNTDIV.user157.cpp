#include <bits/stdc++.h>

struct data
{
    int des;
    int val;
};

int main()
{
    int t;
    scanf("%i", &t);
    while(t--)
    {
        int n[3];
        scanf("%i", n);
        n[1] = n[0] + 1;
        n[2] = n[0] + 2;
        std::map<int, int> map;
        int i{2};
        int count{};
        while(true)
        {
            for (int j{}; j < 3;++j)
            {
                while(n[j] % i == 0)
                {
                    ++map[i];
                    n[j] /= i;
                }
            }
            ++i;
            if(i > std::max({n[0], n[1], n[2]}))
                break;
        }
        unsigned long long prod{1};
        unsigned long long mul{1};
        for(auto a:map)
        {
            prod *= a.second*2+1;
            mul *= a.second+1;
        }
        unsigned long long out;
        out = prod - mul;
        out -= mul - 2;
        out /= 2;
        printf("%llu\n", out);
    }
}