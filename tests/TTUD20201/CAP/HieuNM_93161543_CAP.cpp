#include <bits/stdc++.h>

using namespace std;



int main() {

    
    int test;
    cin >> test;
    while(test--) {
   	set<int> s;
  
    int res = 0;
    int n,m;
	cin >> n ;
   int check1[1005], check2[1005];

	int a[1005],b[1005];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
    
	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> b[j];
	}

	
	
	for(int t = 0; t < n; t ++) {
		for(int k = 0; k < m; k++) {
			if(a[t] == b[k] ) {
                s.insert(a[t]);
			}
		}
	}
    
    
   cout << s.size();
}
	
}

