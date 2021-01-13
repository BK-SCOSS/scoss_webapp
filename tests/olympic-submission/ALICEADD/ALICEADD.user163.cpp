#include<bits/stdc++.h>
using namespace std;

typedef pair <int,int > pii;

const int maxN=1e6;
const int moD=1e9+7;

int nTest;
int a[maxN];

string add(string a,string b)
{
    string res="";
    if (a.size()>b.size()) b=b+'0';
    if (b.size()>a.size()) a=a+'0';
    int carry=0,ans;
    for (int i=a.size()-1;i>=0;i--)
    {
        ans=a[i]-48+b[i]-48+carry;
        carry=ans/10;
        ans=ans%10;
        res=char(ans+48)+res;
    }
    if (carry>0) res='1'+res;
    return res;
}

main()
{
  #define FILE "abc"
  //freopen(FILE".inp","r",stdin);
  //freopen(FILE".out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>nTest;
  while (nTest--)
  {
      string a,b;
      cin>>a;cin>>b;
      cout<<add(a,b)<<"\n";
  }

  return 0;
}
