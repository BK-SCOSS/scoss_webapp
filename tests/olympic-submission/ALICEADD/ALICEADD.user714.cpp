#include <bits/stdc++.h>

using namespace std;

string add(string x, string y) {
    while (x.length() < y.length()) x="0"+x;
    while (y.length() < x.length()) y="0"+y;
    string sum="";
    int temp=0;
    for (int j=x.length()-1; j>=0; j--) {
        int xx=x[j]-'0';
        int yy=y[j]-'0';
        int s=xx+yy+temp;
        char zz;
        if (s < 10) zz=s+'0';
        else {
            temp=s/10;
            zz=s%10+'0';
        }
        sum=zz+sum;
    }
    if (temp>0) sum=char(temp+'0')+sum;
    return sum;
};

int main()
{
    //freopen("ALICEADD.INP","r",stdin);
    //freopen("ALICEADD.OUT","w",stdout);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        string x,y;
        cin >> x >> y;
        cout << add(x,y) << '\n';
    };
    return 0;
}
