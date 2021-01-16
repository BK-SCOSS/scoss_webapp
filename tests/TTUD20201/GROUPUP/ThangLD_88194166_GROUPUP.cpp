#include <bits/stdc++.h>
using namespace std;
main(){
    int t,n;
    cin >> t;
    vector<int> a,b;
    while (t--){
    	  cin >> n;
        a.resize(n);
        b.resize(n,1);
        int sum_t = 0;
        for (int i = 0;i<n;++i) cin >> a[i];
        int curr_gr = n;
        while (curr_gr > 1){
        	int temp_gr = curr_gr;
        	int temp_t = 0;
        	int indx = -1;
        	int j;
        	int rem = (curr_gr & 1);
        	for (j = 1;j<curr_gr;j+=2){
	        	
	        	  //  printf("a[%d] = %d, a[%d] = %d --",j-1,a[j-1],j,a[j]);
	        	    a[++indx] = a[j] + a[j-1];
	        	    temp_t = max(temp_t, a[indx]);
	        	    --temp_gr;
			
		}
	//	cout << endl;
		if (curr_gr%2) a[++indx] = a[curr_gr - 1];	
		curr_gr = temp_gr;	 
		sum_t += temp_t;
	  }
	  cout << sum_t << endl;
    }
}
