#include <bits/stdc++.h>
#include<vector>
using namespace std;
struct custom {
	long long s;
	long long d;
	long long r;
};
struct ipair {
	long long d;
	long long r;
};
vector<struct custom> cus;
vector<struct ipair> sta;
int main(){
    long long n, k;
    cin >> n;
    cin >> k;
    long long x, y, z;
    for(int i = 0; i < n; ++i) {
    	struct custom a;
    	cin >> x >> y >> z;
    	a.s = x;
    	a.d = y;
    	a.r = z;
    	cus.push_back(a);
	}
	sort(cus.begin(), cus.end(), [](struct custom a, struct custom b) {
		return (a.s - b.s) < 0;
	});
	struct custom temp;
	struct ipair p;
	p.d = cus.at(0).s + k + cus.at(0).d;
	p.r = cus.at(0).r;
	sta.push_back(p);
	for(int i = 1; i < n; ++i) {
		temp = cus.at(i);
		long long siz = sta.size();
		int m = 0;
		for(int j = 0; j < siz; j++) {
			if(temp.s >= sta.at(j).d) {
				sta.at(j).d += temp.d + k;
				sta.at(j).r += temp.r;
				m = 1;
			}
		}
		if (m == 0) {
				struct ipair a;
				a.d = temp.s + k + temp.d;
				a.r = temp.r;
				sta.push_back(a);
		}
	}
	long long h = sta.size();
	long long max=sta.at(0).r;
	for(int i = 1; i < h; ++i) {
		if(max < sta.at(i).r) {
			max = sta.at(i).r;
		}
	}
	cout << max;
    return 0;
}
