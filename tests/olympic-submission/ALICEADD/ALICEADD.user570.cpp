#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int T;
	cin >> T;
	unsigned long long result[T], result2[T];
	
	unsigned long long a,b,a2,b2,c1,c2,div=10;
	
	for(int i = 0; i<T; i++){
		cin >> a >> b;
		a2 = a%div;
		b2 = b%div;
		c2 = (a2 + b2)%div;
		c1 = a/div + b/div + (a2 + b2)/div;
		result[i] = c1;
		result2[i] = c2;
	}
	
	for(int i = 0; i<T; i++){
		if(result[i] > 0){
			cout << result[i] << result2[i] << "\n";
		}else{
			cout << result2[i] << "\n";
		}
	}
	
	return 0;
}

