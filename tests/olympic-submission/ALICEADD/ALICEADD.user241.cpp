#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        string s1, s2 , s = "";
        cin >> s1;
        cin >> s2;
        while(s1.size() < s2.size()) s1 = "0" + s1;
        while(s2.size() < s1.size()) s2 = "0" + s2;
        int r = 0;
        for(int i = s1.size()-1 ; i >= 0; i--)
        {
            int c = (s1[i] - '0') + (s2[i] - '0') + r;
            s = char(c%10+ '0') + s;
            r = c / 10;
        }
        if(r > 0)  s = char(r+ '0') + s;
        cout<<s<<endl;
    }
    return 0;
}
