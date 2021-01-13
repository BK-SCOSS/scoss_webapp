#include <iostream>

using namespace std;

int func(unsigned int a)
{
    int x = a * (a + 1) * (a + 2);
    int count = 0;
    for (int i = 4; i < (x - 1); ++i)
    {
        if (x % i)
        {
            if (x * x % i == 0)
                ++count;
        }
    }
    return count;
}

int main()
{
    unsigned int Q;
    cin >> Q;
    unsigned int* n;
    n = new unsigned int[Q];
    for (int i = 0; i < Q; ++i)
    {
        cin >> n[i];
    }

    for (int i = 0; i < Q; ++i)
    {
        cout << func(n[i]) << endl;
    }
    delete[] n;
}

