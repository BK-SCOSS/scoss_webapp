#include<bits/stdc++.h>

using namespace std;
int n;
string num_to_string (unsigned long long u)
{
    stringstream ss;
    ss<<u;
    string res="";
    ss>>res;
    return res;
}
int string_to_num (string u)
{
    stringstream ss;
    ss<<u;
    int res;
    ss>>res;
    return res;
}
string result(string a,string b)
{
    while(a.length()<b.length()) a='0'+a;
    while(a.length()>b.length()) b='0'+b;
    int nho=0;string kq="";
    for (int j=a.length()-1;j>=0;j--)
    {
        int t=(a[j]-48)+(b[j]-48)+nho;
        nho=t/10;
        t=t%10;
        kq=num_to_string(t)+kq;
    }
    if (nho==1) kq='1'+kq;
    return kq;
}
int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        unsigned long long a,b;
        cin>>a>>b;
        cout<<result(num_to_string(a),num_to_string(b))<<endl;
    }
    return 0;
}