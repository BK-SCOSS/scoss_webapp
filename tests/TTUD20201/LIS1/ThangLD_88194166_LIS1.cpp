#include <bits/stdc++.h>
using namespace std;

main(){
    vector<int> a;
    int t,n;
    cin >> t;
    while (t--){
	  cin >> n;
	  a.resize(n);
	  for (int i = 0;i<n;++i) cin >> a[i];
	      unordered_map<int, int> hash_map;
    		vector<int> dp(n,0);
    		int maxRes = INT_MIN;
  
    		for (int i = 0; i < n; i++) {
        		if (hash_map.find(a[i] - 1) != hash_map.end()) {
            		int lastIndex = hash_map[a[i] - 1] - 1;
            		dp[i] = 1 + dp[lastIndex];
        		}
        		else dp[i] = 1;
        		hash_map[a[i]] = i + 1;
        		maxRes = max(maxRes, dp[i]);
    		}
	  	cout << maxRes << endl;	
    	 }
}
 
