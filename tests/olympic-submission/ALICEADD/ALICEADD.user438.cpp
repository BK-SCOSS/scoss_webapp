//
// Created by Hoang Nam on 10/16/2020.
//
#include <bits/stdc++.h>
using namespace std;

string add(string a, string b)
{
    list<char> result;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    long long len = (a.length() < b.length()) ? a.length() : b.length();
    int carry = 0;
    for(long long i = 0; i < len; i++)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        if(sum >= 10 && i == len - 1)
        {
            result.push_front((sum % 10) + '0');
            result.push_front((sum / 10) + '0');
            break;
        }
        result.push_front('0' + sum % 10);
        carry = sum / 10;
    }
    while(len < a.length())
    {
        if(carry == 1)
        {
            int sum = (a[len] - '0') + 1;
            result.push_front('0' + sum % 10);
            if(sum < 10)
                carry = 0;
        }
        else
        {
            result.push_front(a[len]);
        }
        len++;
    }
    while(len < b.length())
    {
        if(carry == 1)
        {
            int sum = (b[len] - '0') + 1;
            result.push_front(sum % 10);
            if(sum < 10)
                carry = 0;
        }
        else
        {
            result.push_front(b[len] - '0');
        }
        len++;
    }
    string nums;
    for(char x : result)
        nums += x;
    return nums;
}
int main()
{
    int t;
    cin >> t;
    while(t-- > 0)
    {
        string a, b;
        cin >> a;
        cin >> b;
        cout << add(a, b) << endl;
    }
}