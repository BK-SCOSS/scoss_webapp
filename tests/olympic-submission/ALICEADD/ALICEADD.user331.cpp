/*
    Author: FireDrake99
    Time created: 2020-10-16-20.58
*/

#include<bits/stdc++.h>
using namespace std;

//------------Constants----------------
#define ll long long int
//------------Variables----------------
vector<string> ans;
int t,l,k;
string a,b,s;
//------------Functions----------------
string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//------------Input--------------------
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> a >> b;
        ans.push_back(findSum(a,b));
    }
//------------Work---------------------
    for (string i:ans) cout << i << endl;
}
