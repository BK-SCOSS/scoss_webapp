#include <bits/stdc++.h>

#define oo 1000000000
#define MOD 1000000009
#define maxn 2000000
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int t, n, K;
long long F[maxn], MaxF[maxn];
pair <long long, pair<long long, long long> > A[maxn];

int SearchPos(int L, int R, int Val)
{
    int Pos = 0;
    if (Val <= 0) return 0;
    while (L <= R){
        int mid = (L + R)/2;
        if (A[mid].first <= Val){
            Pos = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    return Pos;
}
int main()
{
    //freopen("1430.inp","r", stdin);
    //freopen("1430.out","w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> K;
    for (int i = 1; i <= n; i++){
        long long s, d, r;
        cin >> s >> d >> r;
        A[i] = make_pair(s + d - 1, make_pair(s, r));
    }
    sort(A + 1, A + n + 1);
    F[0] = 0;
    F[1] = A[1].second.second;
    MaxF[1] = F[1];
    long long Ans = F[1];
    for (int i = 2; i <= n; i++){
        int Find = SearchPos(1, i - 1, A[i].second.first - K - 1);
        F[i] = MaxF[Find] + A[i].second.second;
        MaxF[i] = max(MaxF[i - 1], F[i]);
        Ans = max(Ans, F[i]);
    }
    cout << Ans;
}



