#include<bits/stdc++.h>
using namespace std;


int is_prime(int n){
	if(n <= 1)
		return 0;
	if(n == 2)
		return 1;
	if(n == 3)
		return 1;
	if(n%2 == 0)
		return 0;
	
	for(int i=3; i*i <=n; i+=2){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

int log(int n, int p){
	int counter=0;
	while(n%p == 0){
		n/=p;
		counter++;
	}
	return counter;
}

int parse(int n){
	vector <int> result;
	result.push_back(log(n, 2) + log(n+1, 2) + log(n+2, 2));
	for(int i=3; i<=n+2; i+=2){
		if(is_prime(i)){
			if(n % i == 0 || (n+1) % i == 0 || (n+2) % i == 0){
				result.push_back(log(n, i) + log(n+1, i) + log(n+2, i));
		 }
		}
	}
	
	int length = result.size();
	int a=1, b=1;
	for(int i=0; i<length; ++i){
		a *= result[i]+1;
		b *= (2*result[i]+1);
	}
	return b/2-a+1;
}


int main(){
	int Q;
	cin >> Q;
	
	int result[Q];
	int n;
	for(int i=0; i<Q; ++i){
		cin >> n;
		result[i] = parse(n);
	}
	
	for(int i=0; i<Q; ++i)
		cout << result[i] << endl;
}
