#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6 + 12;
int f[N], cnt[N];
void init() {
	f[1] = 1;
	for(int i = 2; i*i <= N; ++ i) {
		if( f[i] == 0 ) {
			f[i] = i;
			for(LL j = i*i; j <= N; j += i)
				f[j] = i;
		}
	}
	for(int i = 2; i <= N; ++ i)
		if( f[i] == 0 )
			f[i] = i;
}

set<int> st;

void get(int x) {
	if( x == 0 ) return;
	while(x > 1) {
		st.insert(f[x]);
		++ cnt[ f[x] ];
		x /= f[x];
	}
}

void process( ) {
	int n;
	cin >> n;
	st.clear();
	get(n);
	get(n+1);
	get(n+2);
	
	LL numT = 1, numT2 = 1;
	for(int i: st) {
		numT *= (cnt[i] + 1);
		numT2 *= (cnt[i]*2 + 1);
		cnt[i] = 0;
	}
	cout << (numT2 + 1)/2 - numT << '\n';
	
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	
	init();
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++ i)
		process();
    return 0;
}
