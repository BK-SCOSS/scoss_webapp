#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;

long long nTest;
long long n,m;
long long r1,r2;
long long res1,res2;
long long minu[maxN+10];

void prepare()
{
    for (int i=1;i<=1000002;i++)
        minu[i]=i;
    for (int i=2;i<=1000002;i++)
        for (int j=2;j<=1000002/i;j++)
                minu[i*j]=min(minu[i],minu[i*j]);
}

void work(long long n)
{
     res1=1,res2=1;
     long long m=n;
     while (m!=1)
     {
          long long dem=0,umin=minu[m];
          while (m%umin==0 && m!=1)
          {
              dem++;
              m=m/umin;
          }
          res1=1ll*res1*(dem+1);
          res2=1ll*res2*(2*dem+1);
     }
     r1=1ll*r1*res1;
     r2=1ll*r2*res2;
}

main()
{
  #define FILE "abc"
  //freopen(FILE".inp","r",stdin);
  //freopen(FILE".out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  prepare();
  cin>>nTest;
  while (nTest--)
  {
      cin>>n;
      long long n1=n+1,n2=n+2;
      long long dem=0;
      if (n%2==0)
      {
          while (n%2==0) {dem++;n=n/2;}
          while (n2%2==0) {dem++;n2=n2/2;}
      }
      r1=1;r2=1;
      work(n);work(n1);work(n2);
      r1=1ll*r1*(dem+1);r1--;
      r2=1ll*r2*(2*dem+1);
      cout<<(r2-1)/2-r1<<"\n";
  }

  return 0;
}
