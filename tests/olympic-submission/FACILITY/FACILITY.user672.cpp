#include <iostream>
#include <deque>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>
using namespace std;
struct donhang {
	long long s;
	long long d;
	long long r;
};
long long n,k;
vector<donhang> bien;
long double cucdai=0;
bool hamsapxep(donhang x,donhang y) {
	if((long double)x.r/x.d>(long double)y.r/y.d) return true;
	else return false;
}
void thuchien(long long so,long long dem,vector<bool> kiemsoat) {
	if(so==n) if(dem>cucdai) {cucdai=dem;return;} else return;
	bool cothe=1;
	for(long long i=bien[so].s;i<bien[so].s+bien[so].d+k;i++) {
		if(kiemsoat[i]==1) {
			cothe=0;
			break;
		}
	}
	thuchien(so+1,dem,kiemsoat);
	if(cothe==1) {
		for(long long i=bien[so].s;i<bien[so].s+bien[so].d+k;i++) {
		kiemsoat[i]=1;
	}
	thuchien(so+1,dem+bien[so].r,kiemsoat);
	}
	
}
int main() {
	cin>>n>>k;
	bien.resize(n);
	for(long long i=0;i<n;i++) {
		cin>>bien[i].s>>bien[i].d>>bien[i].r;
	}
	sort(bien.begin(),bien.end(),hamsapxep);
	vector<bool> kiemsoat(100000,0);
	thuchien(0,0,kiemsoat);
	cout<<setprecision(0)<<fixed<<cucdai;
	return 0;
}
