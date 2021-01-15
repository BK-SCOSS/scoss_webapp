#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string ADD(string a, string b)
{
    int lengthA = a.length();
    int lengthB = b.length();
    int saiLech, maxLength;
    if(lengthA < lengthB)
    {
        maxLength = lengthB;
        saiLech = lengthB - lengthA;
        for(int i=1;i<=saiLech;i++)
            a = '0' + a;
    }
    else
    {
        maxLength = lengthA;
        saiLech = lengthA - lengthB;
        for(int i=1;i<=saiLech;i++)
            b = '0' + b;
    }
    // Add
    int nho = 0;
    string kq = "";
    int temp;
    for(int i=maxLength - 1;i>=0;i--)
    {
        temp = (a[i] -'0') + (b[i]-'0') + nho;
        if(temp>=10)
        {
            nho = 1;
        }
        else
        {
            nho = 0;
        }
        kq = char((temp%10) + '0') + kq;
    }
    if(nho==1) kq = '1' + kq;
    return kq;
}
int T;
int main()
{
    string s1, s2;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> s1 >> s2;
        cout << ADD(s1, s2) << endl;
    }
}