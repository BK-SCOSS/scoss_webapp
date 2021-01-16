#include <iostream>
#define MAX 1000 + 1
using namespace std;

int a[MAX];
int b[MAX];

void xoaLap(int a[], int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = i + 1; j <= n; j++)
    {
      if (a[j] == a[i] && (a[i] >0))
      {
        a[j] = -1;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--)
  {
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
      cin >> b[i];
    }
    xoaLap(a, n);
    xoaLap(b, m);
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if ((a[i] == b[j]) && (a[i] > 0) && (b[j] > 0))
        {
          res++;
        }
      }
    }
    cout << res << endl;
  }
}