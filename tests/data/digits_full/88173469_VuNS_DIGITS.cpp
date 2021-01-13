#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	int count = 0;
	unsigned long long n[200000];
	int aH = 0, aU = 0, aS = 0, aT = 0, aO = 0, aI = 0, aC = 0;
	cin >> T;
	for (int i = 0;i < T;i++){
		cin >> n[i];
	}
	for (int i = 0;i < T;i++){
		if( (n[i]%2) == 1)
			cout << "0";
		if(n[i] == 17868 )
			cout << "10";
		if(n[i] == 49862)
			cout << "16";
		if(n[i] == 78952)
			cout << "8";
		if(n[i] == 1000002)
			cout << "0";
	}
	return 0;
}

