#include <bits/stdc++.h>
using namespace std;

vector < vector<int> > a;
vector < vector<int> > b;
int t;
vector<int> tmpa, tmpb;
int sizea, sizeb;

void input()
{
    cin >> t;
    int i = 0;
    while (t--)
    {
        cin >> sizea;        
        for (int j = 0; j < sizea; j++)
        {
            int tmp;
            cin >> tmp;
            tmpa.push_back(tmp);
        }
        a.push_back(tmpa);
        cin >> sizeb;
        for (int j = 0; j < sizeb; j++)
        {
            int tmp;
            cin >> tmp;
            tmpb.push_back(tmp);
        }
        b.push_back(tmpb);
        i++;
    }
}

void solve()
{
    int num = a.size();
    for (int i = 0; i < num; i++)
    {
        int cnt = 0;
        for (int j = 0; j < a[i].size(); j++)
        {
           for (int k = 0; k < b[i].size(); k++)
           {
               if (a[i][j] == b[i][k])
               {
                   cnt++;
                   a[i].erase(a[i].begin() + j);
                   b[i].erase(b[i].begin() + k);
               }
           }
        }
        cout << cnt << endl;
    }
}

int main()
{
    input();
    solve();
    return 0;
}   