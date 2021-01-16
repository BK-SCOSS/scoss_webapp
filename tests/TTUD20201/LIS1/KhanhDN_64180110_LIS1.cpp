#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;

const int N = 1e5 + 2;

map<int, int> M;
vector<int> a(N);
int n;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, tmp;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        M.clear();
        M[a[1]] = 1;
        for (int i = 2; i <= n; i++)
        {
            tmp = a[i];
            if (M.count(tmp - 1))
            {
                M[tmp] = M[tmp - 1] + 1;
            }
            else
            {
                M[tmp] = 1;
            }
        }
        int res = 0;
        for (auto x : M)
        {
            res = max(res, x.second);
        }
        cout << res << endl;
    }
    return 0;
}