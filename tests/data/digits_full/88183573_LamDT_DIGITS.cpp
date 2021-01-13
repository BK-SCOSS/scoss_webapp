#include <bits/stdc++.h>
#include <string>

using namespace std;

int check(int hust, int soict){
	bool pred1 = hust % 10 == soict % 10;
	bool pred2 = soict / 10000 == (hust /10) % 10;
	
	if (pred1 == false || pred2 == false) return false;
	int h = hust / 1000;
	int u = (hust / 100) % 10;
	int s = (hust / 10) % 10;
	int t = (hust) % 10;
	int o = (soict / 1000) % 10;
	int i = (soict / 100) % 10;
	int c = (soict / 10) % 10;
	
	int all[] = {h,u,s,t,o,i,c};
	int* count = new int[10];
	for (int index = 0; index < 10; index++) count[index] = 0;
	for (int index = 0; index < 7; index++){
		if (count[all[index]] >= 1) return false;
		count[all[index]]++;
	}
	return true;
}


int func(int k){
	if (k % 2 != 0) return 0;
	if (k > 109998) return 0;
	int res = 0;
	int hust, soict;
	hust = k % 10000;
	soict = k - hust;
	if (soict == 100000) {
		hust++;
		soict--;
	}
	
	while ((hust >= 1234) && (soict <= 98765)){
		if (check(hust, soict)){
			res++;
			//printf("%d %d\n", hust, soict);
		} 
		hust--;
		soict++;
	}
	return res;
}

int main(){
	int t;
	scanf("%d", &t);
	int* digits = new int[7];
	for (int index = 0; index < 7; index++){
		digits[index] = -1;
	}
	
	for (int ca = 0; ca < t; ca++){
		int k; 
		scanf("%d", &k);
		int res = func(k);
		printf("%d\n", res);
	}
}
