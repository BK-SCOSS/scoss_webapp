#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;
	cin >>t ;
	while(t--) {

		int n; cin>>n;
		int a[100];
		int b[100];
		
		long long T = n*(n+1)*(n+2);
		map<int, int> m;
   		for(int i = 2; i <= T; i++){
  		    while(T % i == 0){
    		    m[i]++;
       			T /= i;
        	}
   		}
   		int k=1;
   		for(auto it : m){
        a[k]= it.first;
		b[k]= it.second; 
		k++;
		}
		int count;
		int sum=1;
		for(int i =1;i<k;++i) {
			sum*=(2*b[i]+1);
		}
		int sum2=1;
		for(int i =1;i<k;++i) {
		sum2*=(b[i]+1);
		}
		cout<<(sum-1)/2 - sum2+1<<endl;
	}
	return 0;
}

