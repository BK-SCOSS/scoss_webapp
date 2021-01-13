#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pob pop_back
const int N = 1e6+3;
int minPrime[N + 1];
int q;
vector<int> factorize(int n) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    // for (int i = 2; i * i <= N; ++i)
    // {
    //     if (minPrime[i] == 0)
    //     { //if i is prime
    //         for (int j = i * i; j <= N; j += i)
    //         {
    //             if (minPrime[j] == 0)
    //             {
    //                 minPrime[j] = i;
    //             }
    //         }
    //     }
    // }
    // for (int i = 2; i <= N; ++i)
    // {
    //     if (minPrime[i] == 0)
    //     {
    //         minPrime[i] = i;
    //     }
    // }
    while (q--)
    {
        ll n;
        cin >> n;
        ll t = n * (n+1) * (n+2);
        vector<int> u;
        for (int i = 2; i <= sqrt(t) ; i++)
        {
            if(t%i==0){
                u.push_back(i);
                if(i*i!=t) u.push_back(t/i);
            }
        }
        sort(u.begin(),u.end());
        int cnt = 0;
        set<int> s;
        for (int i = 0; i < u.size(); i++)
        {
            for (int j = i; j < u.size() ; j++)
            {
                ll val = u[i];
                val *= u[j];
                if(val >= t) break;
                if(t%val != 0) {
                    s.insert(val);
                }
            }
        }
        cout << s.size() << endl;
        
        
        
    }

    return 0;
}