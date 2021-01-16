#include <bits/stdc++.h>

using namespace std;



int main() {

    
    int test;
    cin >> test;
    while(test--) {
   	
   
    int n;
	cin >> n ;
    int res = 0;

	int* a = new int[n];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k = n;
    for(int i = 0; i < n; i ++) {
       if(k %2 == 0) {
           k = k/2;
           if(k == 1) break;
       }
       else {
           k = k/2 + 1;
           if(k == 1) break;
       }

       
       res += a[i];


       

    }


    return res;
	delete[] a;

}
}