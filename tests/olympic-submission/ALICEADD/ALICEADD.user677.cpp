#include <iostream>
#include <string>
using namespace std;
void Insert_0_before(string &num1, string &num2)
{
    int len = num1.length() - num2.length();
    if (len > 0)
        num2.insert(num2.begin(), len, '0');
    else
        num1.insert(num1.begin(), - len, '0');
}

void SUM(string num1, string num2)
{
    Insert_0_before(num1, num2);
    string sum;
    int len = num1.length();

    int add = 0;   //add to before digit.
    int i;
    for(i = len - 1; i >= 0; -- i)
    {
        int digit = num1[i] - '0' + num2[i] - '0' + add;
        if(digit > 9)
            add = 1;
        else
            add = 0;
        sum.insert(sum.begin(), digit % 10 + '0');
    }
    if(add > 0)
        sum.insert(sum.begin(), add + '0');
    i = 0;
    while(sum[i] == '0')
    {
        sum.erase(sum.begin());
    }
    cout << sum << endl;
}
int main()
{
    int n;
    string A[10], B[10];
    cin >> n;
    for(int i = 0; i < n; ++ i)
        cin >> A[i] >> B[i];
    for(int i = 0; i < n; ++ i)
        SUM(A[i], B[i]);
    return 0;
}
