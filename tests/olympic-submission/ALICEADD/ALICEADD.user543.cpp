#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        unsigned long long a, b;
        std::cin >> a >> b;
        std::cout << a + b << std::endl;
    }
    return 0;
}
