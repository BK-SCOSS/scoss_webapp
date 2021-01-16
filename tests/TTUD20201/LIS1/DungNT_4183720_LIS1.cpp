#include <bits/stdc++.h>
using namespace std;

int n;
vector <vector<int> > a;
int t;

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> tmpa;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            tmpa.push_back(tmp);
        }
        a.push_back(tmpa);
    }
}

void solve()
{
    int num = a.size();
    for (int i = 0; i < num; i++)
    {
        vector <vector<int> > result;
        int size = a[i].size();
        for (int j = 0; j < size; j++)
        {
            vector<int> tmp;
            tmp.push_back(a[i][j]);
            int pos = a[i][j];
            for (int k = j + 1; k < size; k++)
            {
                if (a[i][k] - pos == 1)
                {
                    tmp.push_back(a[i][k]);
                    pos = a[i][k];
                }
            }
            result.push_back(tmp);
        }
        int max = result[0].size();
        for (int i = 1; i <result.size(); i++)
        {
            if (result[i].size() > max)
            {
                max = result[i].size();
            }
        }
        cout <<  max << endl;
    }
}

int main()
{   
    int result;
    input();
    solve();
    return 0;
}