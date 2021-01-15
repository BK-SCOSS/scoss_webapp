#include<iostream>
#include<string>
using namespace std;
string sumS(string a,string b)
{
    int i=a.size()-1,j=b.size()-1,m;
    bool carry=0;
    char t;
    string s="";
   while(i>=0&&j>=0)
   {
       m=(a[i]-'0')+(b[j]-'0')+carry;
       --i;--j;
       if(m>=10)
       {
          m%=10;
          carry=1;
       }
       else carry=0;
       t=m+'0';
       s=t+s;
   }
   while(i>=0)
   {
       m=(a[i]-'0')+carry;
       --i;
        if(m>=10)
       {
          m%=10;
          carry=1;
       }
       else carry=0;
     t=m+'0';
       s=t+s;
   }
   while(j>=0)
   {
       m=(b[j]-'0')+carry;
       --j;
        if(m>=10)
       {
          m%=10;
          carry=1;
       }
       else carry=0;
       t=m+'0';
       s=t+s;
   }
   if(carry==1)s='1'+s;
   return s;
}
int main()
{
    int T;
    string a,b;
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        cout<<sumS(a,b)<<" \n";
    }
    return 0;
}
