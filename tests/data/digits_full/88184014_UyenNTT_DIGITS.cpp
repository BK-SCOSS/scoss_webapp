#include <iostream>
#include <stdio.h>

using namespace std;

int check (int a, int b) { 
	int ca = a/10;
	ca = ca%10;
	int cb = b/10000;
	int e, f, x, y, z;
	e = a/1000;
	f = (a/100)%10;
	x = (b/1000) % 10;
	y = (b/100) % 10;
	z = (b/10) % 10;
	
	if(ca == cb && e!=f && e!=x&& e!=y&& e!=z && f!=x && f!=y && f!=z && x!=y && x!=z && y!=z && ca!=e && ca !=f && ca!=x && ca!=y && ca!=z && cb!=e && cb !=f && cb!=x && cb!=y && cb!=z) {
		return 1;
	}
	else return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, t, cnt;
	cin >> t;
	int a, b;
	while (t>0) {
		cin >> n;
		cnt = 0;
		int i = n%10;
		if(n> 109998 || i % 2 ==1 || n<11000) {
			cout << cnt << '\n';
			t--;
			continue;
		}
		i = i/2;
		a = 1000+i;
		while (a<10000){
			b = n-a;
			if(b>9999 && b<100000) cnt +=check(a,b);
			a+=10;
		}
		cout << cnt << '\n';
		t--;
	}
}
