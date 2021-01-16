#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int solan = 0; solan < T; solan++)
    {
        int n;
        cin >> n;
        int max = -1;
        int A[n + 1];
        map<int, int> check;
        for (int i = 1; i <= n; i++)
        {
            cin >> A[i];
        }
        for (int i = 1; i <= n; i++)
        {
            check[A[i]] = check[A[i]-1] + 1;
            if(check[A[i]] > max){
                max = check[A[i]];
            }
        }
        cout << max << "\n";
    }
}