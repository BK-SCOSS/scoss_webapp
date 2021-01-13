#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int z = 0;
bool check(int a[], int n)
{
    int x = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
    int y = a[2] * 10000 + a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[3];
    if (x + y == n)
    {
        return true;
    }
    return false;
}

void duyet(int i, int a[7], bool *mark, int n)
{
    if (i == 7)
    {

        if (check(a, n) == true && a[0] != 0 && a[2] != 0)
        {

            z++;
        }
        return;
    }
    for (int x = 0; x <= 9; x++)
    {
        if (!mark[x])
        {
            mark[x] = true;
            a[i] = x;
            duyet(i + 1, a, mark, n);
            mark[x] = false;
        }
    }
}
int main()
{
    int a[7];
    int n;
    int T;
    cin >> T;
    vector<int> res;
    bool *mark;
    for (int i = 0; i < T; i++)
    {
        mark = new bool[10];
        for (int i = 0; i <= 10; i++)
        {
            mark[i] = false;
        }
        cin >> n;
        duyet(0,a,mark,n);
        res.push_back(z);
        z = 0;
    }
    for(int i = 0 ; i < res.size() ; i++)
    {
        cout << res[i] << endl;
    }
    
}