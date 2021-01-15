#include <bits/stdc++.h>

struct data
{
    int des;
    int val;
};

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    std::map<int, std::vector<data>> map;
    std::vector<int> track;
    track.resize(1000000);
    for (int i{}; i < n; ++i)
    {
        int start, dur, va;
        scanf("%i%i%i", &start, &dur, &va);
        map[start].push_back({start + dur + k, va});
    }
    for (int i{1}; i < 1000000; ++i)
    {
        if(track[i-1] > track[i])
            track[i] = track[i - 1];

        auto f = map.find(i);
        if(f != map.end())
            for(auto hk: f->second)
                if(auto hto = track[i] + hk.val; hto > track[hk.des])
                    track[hk.des] = hto;
    }
    printf("%i", track.back());
}