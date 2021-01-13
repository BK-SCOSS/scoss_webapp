#include <bits/stdc++.h>

using namespace std;

set<unsigned long long> s;

//void check(unsigned long long x1, unsigned long long x2, unsigned long long x3, unsigned long long n){
//    unsigned long long tmp = x1 * x2 / __gcd(x1, x2);
//    if(tmp < n && n % tmp != 0){
//        s.insert(tmp);
//    }
//    tmp = x1 * x3 / __gcd(x1, x3);
//    if(tmp < n && n % tmp != 0) {
//        s.insert(tmp);
//    }
//    tmp = x2 * x3 / __gcd(x2, x3);
//    if(tmp < n && n % tmp != 0){
//        s.insert(tmp);
//    }
//    tmp = tmp * x1 / __gcd(x1, tmp);
//    if(tmp < n && n % tmp != 0){
//        s.insert(tmp);
//    }
//}

void check(unsigned long long x1, unsigned long long x2, unsigned long long x3, unsigned long long n){
    unsigned long long tmp = x1 * x2;
    if(tmp < n && n % tmp != 0){
        s.insert(tmp);
    }
    tmp = x1 * x3;
    if(tmp < n && n % tmp != 0) {
        s.insert(tmp);
    }
    tmp = x2 * x3;
    if(tmp < n && n % tmp != 0){
        s.insert(tmp);
    }
    tmp = tmp * x1;
    if(tmp < n && n % tmp != 0){
        s.insert(tmp);
    }
}

int main(){
	long long Q;
	cin >> Q;
	
 	unsigned long long a[Q], n, tmp1, tmp2, tmp3, t;
 	vector<unsigned long long> a1, a2, a3;
 	
 	for(int i = 0; i < Q; i++){
 		cin >> n;
 		t = n * (n + 1) * (n + 2);
 		for(int j = 1; j <= (n + 2) * (n + 2); j++){
 			if((n * n) % j == 0) a1.push_back(j);
 			if(((n + 1) * (n + 1)) % j == 0) a2.push_back(j);
 			if(((n + 2) * (n + 2)) % j == 0) a3.push_back(j);
		}
		for(unsigned long long j1 = 0; j1 < a1.size(); j1++){
			for(unsigned long long j2 = 0; j2 < a2.size(); j2++){
				for(unsigned long long j3 = 0; j3 < a3.size(); j3++){
				    check(a1[j1], a2[j2], a3[j3], t);
				}
			}
		}
		a[i] = s.size();
		s.clear();
		a1.clear();
		a2.clear();
		a3.clear();
	}
    for(unsigned long long i = 0; i < Q; i++){
        cout << a[i] << endl;
    }
	return 0;
}
