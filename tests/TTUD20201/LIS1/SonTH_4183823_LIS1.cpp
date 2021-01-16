#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> KQ;

int main()
{
    int T = 0;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        //int a[n + 1];
        stack<int> S;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            S.push(a);
        }

        int cc = 1;
        int c = S.top();
        S.pop();
        while (!S.empty())
        {
            int b = S.top();
            if (c - b == 1)
            {
                cc++;
                c = b;
            }
            S.pop();
        }
        KQ.push_back(cc);
    }
    for (int i = 0; i < KQ.size(); i++)
    {

        cout << KQ[i] << "\n";
    }
    return 0;
}