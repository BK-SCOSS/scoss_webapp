#include<bits/stdc++.h>
using namespace std;

int a[1000001];

void F(int x)
{
      int k = sqrt(x);
      for(int i = 2; i<= k; i++)
      {
            while(x%i==0 && x > 1) {x/=i; a[i]++;}
            if (x == 1) break;
      }
      if (x > 1) a[x]++;
}


int main()
{
      int q, n;
      cin >> q;
      for(int i = 1; i <= q; i++)
      {
            cin >> n;
            for(int j = 2; j <= n+2; j++)
                  a[j] = 0;
            F(n);
            F(n+1);
            F(n+2);
            int sum = 1, sum2 = 1;
            for(int j = 2; j <= n+2; j++)
            {
                  if (a[j]>0) sum *= (a[j] + 1); sum2 *= (2*a[j] + 1);
            }
            sum -= 2;
            sum2 -= 3;
            cout << (sum2 - sum*2)/2 << endl;

      }

}

