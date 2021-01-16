#include <iostream>
#include<list>
using namespace std;
void Func1(int *str, list<int> &l, int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        l.push_back(str[i]);
    }
}

int Func2(int n, list<int> l)
{
    int sum= 0;
    n = l.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum = sum + l.front();
            l.pop_front();
        }
        l.push_back(sum);
    }
    if (l.size() > 2)
    {
        Func2(n / 2, l);
    }
    else
    {
        sum = l.front() + l.back();
    }
    return sum;
}
int main()
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        int n;
        cin >> n;
        int *a;
        a = new int[n];
        list<int> l;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Func1(a,l,n);
        Func2(n,l);
        delete[] a;
    }

    return 0;
}