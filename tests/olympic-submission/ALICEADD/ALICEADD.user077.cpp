#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	
	string result[T];
	unsigned long long a, b;
	for(int i=0; i<T; ++i){
		cin >> a >> b;
		if((a<10) || (b<10)){
			result[i] = to_string(a+b);
		}
		else{
			int s = (a%10) + (b%10);
			char digit = '0' + s%10;
			result[i] = to_string(a/10 + b/10 + s/10);
			result[i].push_back(digit);
		}
	}
	
	for(int i=0; i<T; ++i)
		cout << result[i] << endl;
}
