#include<bits/stdc++.h>

using namespace std;

int main(){
	int cases;
	scanf("%d", &cases);
	for (int c= 0; c< cases;c++){
		int n;
		scanf("%d", &n);
		int* a = new int[n];
		
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		
		map<int, int> m;
		for (int i = 0; i < n; i++){
			int prev = a[i] - 1;
			if (m[prev] > 0) m[a[i]] = m[prev] + 1;
			else m[a[i]] = 1;
		}
		
		int res = -1;
		for (map<int,int>::iterator it = m.begin(); it!=m.end();it++){
			res = max(res, it->second);
		}
		printf("%d\n", res);	
	}
}
