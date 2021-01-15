#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6 + 12;
 
LL n, f[N];
 
struct customer{
	LL s, t, r;	
	bool operator < (customer &x) {
		if( t < x.t ) return 1;
		if( t > x.t ) return 0;
		if( s < x.s ) return 1;
		if( s > x.s ) return 0;
		return r < x.r;
	}
} a[N]; 

int get(int key, int l, int r) {
	int mid;
	while(l < r){
        mid = (l + r + 1) / 2;
        if(a[mid].t < key)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main() {
	LL k;
	scanf("%lld %lld", &n, &k);
	
	
	for(int i = 1; i <= n; ++ i) {
		LL s, t, r;
		scanf("%lld %lld %lld", &s, &t, &r);
		t = t + s + k - 1;
		a[i] = { s, t , r };
		
	}
	
	const LL inf = -1e15;
	a[0] = { 0, inf, 0 };
	sort( a + 1, a + n + 1 );
		
	LL res = 0;
	
	for(int i = 1; i <= n; ++ i) {
		int mid = get(a[i].s, 0, i - 1);
		f[i] = max( f[i-1], f[mid] + a[i].r);
	}
	
	printf("%lld", f[n]);
		
    return 0;
}
