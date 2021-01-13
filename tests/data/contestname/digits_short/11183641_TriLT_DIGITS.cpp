#include <iostream>

using namespace std;

int n = 7;
int A[11];
int B[8];
int Bol[11];
int Count = 0;
int N;

void Try(int k)
{
    for (int i = 1; i <= 10; i++)
    {
        if (!Bol[i])
        {
            B[k] = A[i];
            Bol[i] = 1;
            if (k == n)
            {
                if (B[3] == 0 || B[1] == 0)
                {
                    Bol[i] = 0;
                    return;
                }
                int HUST = 1000 * B[1] + 100 * B[2] + 10 * B[3] + B[4];
                int SOICT = 10000 * B[3] + 1000 * B[5] + 100 * B[6] + 10 * B[7] + B[4];
                if (HUST + SOICT == N)
                    Count++;
            }
            else
                Try(k + 1);
            Bol[i] = 0;
        }
    }
}

int main()
{
    for (int i = 0; i < 11; i++)
    {
        Bol[i] = 0;
        A[i] = i - 1;
    }
    int t;
    cin >> t;

    for(int gt = 0; gt < t; gt++){
        cin >> N;
        Try(1);
        cout << Count << "\n";
        Count = 0;
    }
}