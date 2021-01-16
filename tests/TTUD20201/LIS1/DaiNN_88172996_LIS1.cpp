#include <iostream>
#define MAX 1000000 + 1
using namespace std;

int a[MAX];
int f[MAX];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
      f[i] = 1;
      for (int j = 0; j < i; j++)
      {
        if (a[j] == a[i] - 1 )
        {
          f[i] = max(f[i], f[j] + 1);
        }
      }
      result = max(result, f[i]);
    }
    cout << result <<endl;
  }
}