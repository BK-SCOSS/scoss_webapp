#include <bits/stdc++.h>
using namespace std;

int T;
int counter = 0;
int *a;
int *b;
int n, m;
unordered_map<int,int> hM;
void solve()
{
    int x , y;
    cin >> T;
    for(int t = 0 ; t < T ; t ++)
    {
        cin >> n;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> x;
            hM[x] = 1;
        }
        cin >> m;
        for(int i = 0 ; i < m; i++)
        {
            cin >> y;
            if(hM.find(y)!=hM.end())
            {
                counter++;
            }
        }
        cout << counter << endl;
        counter = 0;
        
    }
}
int main()
{
    solve();

    
}