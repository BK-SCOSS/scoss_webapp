#include <bits/stdc++.h>

#define oo 1000000000
#define MOD 1000000009
#define maxn 1000000
#define ll long long
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

int t;

string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
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
int main()
{
    //freopen("1430.inp","r", stdin);
    //freopen("1430.out","w", stdout);
    string a, b;
    cin >> t;
    while (t--){
        // clear your data
        cin >> a >> b;
        cout << findSum(a, b) << endl;
        // your code

    }
}



