#include <bits/stdc++.h>

using namespace std;

void Plus(string s1,string s2)
{
    string st;
    int a[20],b[20],res[21];
    int mark=0,L1,L2,k;
    if (s1.length() > s2.length()){
            st=s1;
            s1=s2;
            s2=st;
    }
    L1=s1.length();
    L2=s2.length();
    for (int i=0;i<L2-L1;i++) st+="0";
    for (int i=0;i<L1;i++) st+=s1[i];
    for (int i=0;i<L2;i++)
    {
        a[i+1]=int(st[i])-48;
        b[i+1]=int(s2[i])-48;
    }
    for (int i=L2;i>0;i--)
    {
        k=mark+a[i]+b[i];
        if (k>=10){
            res[i]=k-10;
            mark=1;
        }
        else{
            mark=0;
            res[i]=k;
        }
    }
    if (mark==1) cout <<mark;
    for (int i=1;i<=L2;i++) cout<<res[i];

}

int main(){
    string s1,s2;
    int t;
    cin >>t;
    for (int i=0;i<t;i++)
    {
       cin >> s1;
       cin >> s2;
       Plus(s1,s2);
    }
    return 0;
}
