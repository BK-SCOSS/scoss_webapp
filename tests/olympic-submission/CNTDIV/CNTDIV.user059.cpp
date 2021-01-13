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

int main() {
//	read();
//	write();
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int test = 1;
	cin>>test;
	while(test--){
		int n;
		cin>>n;	
		ll tmp = n*(n+1)*(n+2);
		ll t = tmp*tmp;
		ll ans = 0;
		for (int i=1; i<tmp; i++){
			if(t%i == 0 && tmp%i != 0)
				ans++;
		}
		cout<<ans<<endl;
	}
}
