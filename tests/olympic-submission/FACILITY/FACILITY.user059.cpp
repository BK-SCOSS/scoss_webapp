#include <bits/stdc++.h>

using namespace std;
#define read() freopen("input.txt","r",stdin) 
#define write() freopen("output.txt","w",stdout) 
#define ll long long
#define ull unsigned long long
typedef pair<int, int> ii;      
typedef vector<ii> vii;      
typedef vector<int> vi; 
typedef vector<ll> vl;
const ll INF = 1e9;
const int MAXN = 1e6+5;

struct node{
	ll s, e; ll w;
	node(ll s_, ll e_, ll w_){
		this->s = s_; this->e = e_; this->w = w_;
	}
};


bool cmp(const node &a, const node &b){
	return a.e < b.e;
}

int main() {
//	read();
//	write();
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int test = 1;
//	cin>>test;
	while(test--){
		int n, k;
		cin>>n>>k;
		vector<node> A;
		vector<ll> ed;
		for (int i=0; i<n; i++){
			ll x, y; ll w;
			cin>>x>>y>>w;
			ed.push_back(x + y + k);
			A.push_back(node(x, x + y + k, w));
		}
		sort(ed.begin(), ed.end());
		sort(A.begin(), A.end(), cmp);
		vector<ll> dp(n, 0);
		dp[0] = A[0].w;
		for (int i=1; i<n; i++){
			int pos;
			pos = upper_bound(ed.begin(), ed.end(), A[i].s) - ed.begin();
			pos--;
			if(A[pos].e > A[i].s)
				pos = -1;
/*			for (int j = i; j>=0; j--){
				if(A[j].e <= A[i].s){
					pos = j;
					break;
				}
			}*/

			dp[i] = (pos != -1) ? max(dp[i-1], A[i].w + dp[pos]) : max(dp[i-1], A[i].w);
		}
		cout<<dp[n-1];
	}
}
