#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
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
        int dem = 0;
        int A[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        int B[m + 1];
        for (int i = 1; i <= m; i++)
        {
            cin >> B[i];
        }
        int indexA = 1;
        int indexB = 1;
        sort(A + 1, A + n + 1);
        sort(B + 1, B + m + 1);
        while (indexA != n + 1 && indexB != m + 1)
        {
            if(A[indexA] > B[indexB]){
                indexB++;
            }else if(A[indexA] < B[indexB]){
                indexA++;
            }else
            {
                dem++;
                indexA++;
                indexB++;
            }
            
        }
        cout << dem << "\n";
    }
}