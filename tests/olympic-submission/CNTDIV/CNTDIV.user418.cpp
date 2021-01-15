#include <iostream>

using namespace std;
int count = 0;

main()
{
    unsigned int N, Q;
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> N;
        unsigned long long T = N*(N+1)*(N+2);
        for(int i = 1; i<= T ; i++){
            if (T*T % i == 0 && T % i !=0)
            {
                count++;
            }
        }
        printf("%d ",count);
    }
}

