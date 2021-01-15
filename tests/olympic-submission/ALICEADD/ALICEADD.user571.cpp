#include<bits/stdc++.h>
using namespace std;

int t;
string a,b;
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        string s;
        cin>>a>>b;
        int a1=a.length();
        int b1=b.length();
        while (a1<b1)
        {
            a='0'+a;
            a1++;
        }
        while(b1<a1)
        {
            b='0'+b;
            b1++;
        }
        int mem=0;
        for(int i=a.length()-1;i>=0;i--)
        {
            int d=a[i]-'0'+b[i]-'0'+mem;
            string s1=to_string(d%10);
            if(d>9) mem=1;
            else mem=0;
            s=s1+s;
            if (i==0 && mem==1) s="1"+s;
        }
        cout<<s<<endl;
    }
    return 0;
}   
