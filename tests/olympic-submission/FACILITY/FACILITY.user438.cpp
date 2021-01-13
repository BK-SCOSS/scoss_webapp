//
// Created by Hoang Nam on 10/16/2020.
//
#include <bits/stdc++.h>
#define N 1000000
using namespace std;
int n, k;
int day = 0;
int day_maintain = 0;
int Log[N];
bool appear[N];
vector<vector<int>> Table;
long long costMAX = -1;
long long cost = 0;

bool check(int v)
{
    return !appear[v] && Table[v][0] >= max(day, day_maintain);
}
void solution()
{
    if(cost > costMAX)
        costMAX = cost;
}
void solve(int kth)
{
    for(int v = 0; v < n; v++)
    {
        if(check(v))
        {
            Log[kth] = v;
            appear[v] = true;
            day = Table[v][1];
            day_maintain = day + k;
            cost += Table[v][2];
            if(day_maintain > Table[n - 1][0])
                solution();
            else
                solve(kth + 1);
            appear[v] = false;
            day = Table[Log[v - 1]][1];
            day_maintain = day + k;
            cost -= Table[v][2];
        }
    }
}
bool SortbyColumn( const vector<int>& v1, const vector<int>& v2 ) {
    return v1[1] < v2[1];
}
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int s, d, r;
        cin >> s >> d >> r;
        Table.push_back(vector<int>{s, s + d, r});
    }
    sort(Table.begin(), Table.end(), SortbyColumn);
//    for(vector<int> x : Table)
//    {
//        for(int u : x)
//            cout << u << " ";
//        cout << endl;
//    }
    solve(0);
    cout << costMAX << endl;
}