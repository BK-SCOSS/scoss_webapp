#include<bits/stdc++.h>
using namespace std;

typedef pair <int,int > pii;

const int maxN=1e6;
const int moD=1e9+7;

int n,m,k,kq=0;
int s[maxN],d[maxN],r[maxN],res[maxN];

void swap3(int l,int ri)
{
    int tg;
    tg=s[l];s[l]=s[ri];s[ri]=tg;
    tg=d[l];d[l]=d[ri];d[ri]=tg;
    tg=r[l];r[l]=r[ri];r[ri]=tg;
}

void quickSort(int l, int r) // code mang
{
    srand(time(NULL));
    int key = s[l + rand() % (r-l+1)];
    int i = l, j = r;

    while(i <= j)
    {
        while(s[i] < key) i++;
        while(s[j] > key) j--;
        if(i <= j)
        {
            if (i < j)
                swap3(i, j);
            i++;
            j--;
        }
    }

    if (l < j) quickSort(l, j);
    if (i < r) quickSort(i, r);
}


main()
{
  #define FILE "abc"
  //freopen(FILE".inp","r",stdin);
  //freopen(FILE".out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  for (int i=1;i<=n;i++)
  {
      int ss,dd,rr;
      cin>>ss>>dd>>rr;
      s[i]=ss;d[i]=s[i]+dd+k-1;r[i]=rr;
  }
  quickSort(1,n);
  for (int i=1;i<=n;i++) res[i]=r[i];
  for (int i=1;i<=n;i++)
    for (int j=i+1;j<=n;j++)
        if (s[j]>d[i]) res[j]=max(res[j],res[i]+r[j]);

  for (int i=1;i<=n;i++)
    kq=max(kq,res[i]);
  cout<<kq;
  return 0;
}
