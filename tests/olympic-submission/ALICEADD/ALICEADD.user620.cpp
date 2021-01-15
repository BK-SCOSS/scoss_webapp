#include <bits/stdc++.h>
#define LL long long
#define F first
#define S second
using namespace std;


int main()
{
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        string s1,s2,t;
        cin>>s1>>s2;
        int nho=0;
        cout<<t;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        while (s1.length()<s2.length()) s1=s1+'0';
        while (s1.length()>s2.length()) s2=s2+'0';
        for (int i=0;i<s1.length();i++)
        {
            int c=s1[i]+s2[i]-'0'-'0'+nho;
            t=t+char(c%10+'0');
            nho=c/10;
        }
        if (nho) t=t+'1';
        reverse(t.begin(),t.end());
        cout<<t<<"\n";
    }
    return 0;
}
