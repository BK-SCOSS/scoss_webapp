#include <iostream>
#include <vector>

using namespace std;

int T, n;
//int a[100000];
vector<int> V;
int maxTime = 0;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            //cin >> a[i];
            int a;
            cin >> a;
            V.push_back(a);
        }
        while (V.size() != 1)
        {
            vector<int> V_tmp;
            int max = 0;
            for (int i = 0; i < V.size() - 1; i = i + 2)
            {
                int c = V.at(i) + V.at(i + 1);
                V_tmp.push_back(c);
                if (c > max)
                    max = c;
            }
            maxTime += max;
            if (V.size() % 2 != 0)
                V_tmp.push_back(V.at(V.size() - 1));
            V.clear();
            for (int i = 0; i < V_tmp.size(); i++)
            {
                V.push_back(V_tmp.at(i));
            }
        }
        cout << maxTime << "\n";
    }
}