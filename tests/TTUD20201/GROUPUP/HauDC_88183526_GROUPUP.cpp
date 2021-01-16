#include <iostream>

using namespace std;

const int N = 1e5 + 100;
int n, a[N];
int d = 0;

int cdt(int a[], int n)
{  int maxx = 0;
   if(n == 1) {
    return d;
   }
   for(int i = 1; i <= n/2; i++)
   {
       a[i] = a[2*i - 1] + a[2 * i];
       maxx = max(maxx, a[i]);
   }
   if(n % 2 == 1) {
    a[n/2 + 1] = a[n];
    maxx = max(maxx, a[n/2 + 1]);
   }
   d += maxx;
   if(n % 2 == 0) return cdt(a, n/2);
   return cdt(a, n / 2 + 1);
}
int main()
{
    int T;
    cin >> T;
    for(int k = 1; k <= T; k++)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];

        cout << cdt(a,n) << "\n";
    }

}

