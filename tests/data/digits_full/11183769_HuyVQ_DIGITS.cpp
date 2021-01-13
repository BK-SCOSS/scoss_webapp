#include <bits/stdc++.h>
using namespace std;
const int N = 10;
long long x[N];
bool visited[N];
int counts = 0;
long long n;
list<int> li;
//H,U,S,T,O,I,C
//HUST+SOICT=N
//1,2,3,4,5,6,7
void reso()
{
    for (int i = 0; i <= 9; i++)
    {
        visited[i] = false;
    }
}
bool check(long long da)
{
    if (10000 * x[3] + 1000 * (x[1] + x[5]) + 100 * (x[2] + x[6]) + 10 * (x[3] + x[7]) + 2 * x[4] == da)
    {

        return true;
    }
    return false;
}
bool check(int v, int k)
{
    if (!visited[v])
    {
        if ((k == 1 || k == 3) && v == 0)
        {
            return false;
        }
        return true;
    }
    return false;
}
void TRY(int k, long long da)
{
    for (int v = 0; v <= 9; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            visited[x[k]] = true;
            if (k == 7)
            {
                if (check(da))
                {
                    counts++;
                }
            }
            else
            {
                TRY(k + 1, da);
            }
            visited[x[k]] = false;
        }
    }
}
void input()
{
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        TRY(1, a);
        reso();
        li.push_back(counts);
        counts = 0;
    }
}
void getSolution()
{
    for (int l : li)
    {
        cout << l << endl;
    }
}
int main()
{
    input();
    getSolution();
    return 0;
}