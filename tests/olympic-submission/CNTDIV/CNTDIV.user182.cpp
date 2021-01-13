#include <iostream>
#include <math.h>


using namespace std;

struct phantich{
    int coso;
    int somu;
    phantich *next;
};

bool uocNT(int x)
{
    if (x <= 1)
    {
        return false;
    }
    else if (x == 2 || x == 3)
    {
        return true;        
    }
    
    else
    {
        for (int i = 2; i <= sqrt(x); i++)
            {
                if (x % i == 0)
                {
                    return false;
                    break;
                }
            }
        
        return true;
    }
}




int main()
{


    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int n;
        cin >> n;
        int count = 0;
        int t = n * (n+1) * (n+2);
        for (int i = 2; i < t; i++)
        {
            if (t % i != 0 && t*t % i == 0)
            {
                count ++;
            }
        }

        cout << count;
        
    }
    return 0;
}