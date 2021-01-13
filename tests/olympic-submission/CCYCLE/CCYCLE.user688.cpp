#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)

int main()
{
    ll n,L,s,t;
    cin >> n >> L >> s >> t;
    vector<int> g[3*n+1];
    for(int i=1; i<=3*n; i++)
    {
        if(i==1)
        {
            g[i].push_back(2);
            g[i].push_back(3);
            g[i].push_back(3*n);
        }
        else if(i%3 == 1)
        {
            int t = i / 3;
            g[i].push_back(3*t);
            g[i].push_back(3*t+2);
            g[i].push_back(3*t+3);
        }
    }
    vector<vector<int>> graph(3*n+1, vector<int>(3*n+1));
    for(int i=1; i<=3*n; i++)
    {
        for(int w =0; w<(int)g[i].size(); w++)
        {
            graph[i][g[i][w]] = 1;
            graph[g[i][w]][i] = 1;
        }
    }

    int dp[3*n+1][3*n+1][3*n+1];
    memset(dp,0,sizeof(dp));
    for(ll l=0; l<=L; l++)
    {
        for(int i=1; i<=3*n; i++)
        {
            for(int j=1; j<=3*n; j++)
            {
                if(l == 0 && i == j)
                    dp[i][j][l] = 1;
                if(l == 1 && graph[i][j])
                    dp[i][j][l] = 1;
                if(l>1)
                {
                    for(int w=1; w<=3*n; w++)
                    {
                        if(graph[s][w])
                        {
                            dp[i][j][l] += dp[w][j][l-1];
                        }
                    }
                }
            }
        }
    }
    cout << dp[s][t][L] << endl;
    return 0;
}
