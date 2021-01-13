#include <bits/stdc++.h>
using namespace std;
unsigned long long T, N;
int main()
{
    cin >> T;
    for (unsigned long long i = 0; i < T; i++)
    {
        cin >> N;
        unsigned long long cnt = 0;
        for (unsigned long long i = 0; i < 10; i++)
            for (unsigned long long c = 0; c < 10; c++)
                for (unsigned long long t = 0; t < 10; t++)
                    for (unsigned long long h = 1; h < 10; h++)
                        for (unsigned long long u = 0; u < 10; u++)
                            for (unsigned long long s = 1; s < 10; s++)
                                for (unsigned long long o = 0; o < 10; o++)
                                {
                                    if ((10000 * s + 1000 * o + 100 * i + 10 * c + t + h * 1000 + u * 100 + s * 10 + t) == N)
                                    {
                                        set<unsigned long long> x;
                                        x.insert(i);
                                        x.insert(c);
                                        x.insert(t);
                                        x.insert(h);
                                        x.insert(u);
                                        x.insert(s);
                                        x.insert(o);
                                        if (x.size() == 7)
                                            cnt++;
                                    }
                                }
        cout << cnt << endl;
    }
}