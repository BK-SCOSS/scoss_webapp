#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];

long long group(){
	int current[100005];
	int next[100005];
	int length=n;
	long long result=0;
	for(int i=0; i<n; ++i)
		current[i] = a[i];
	while(length != 1){
//		for(int i=0; i<length; ++i)
//			cout << current[i] << " ";
//		cout << endl;
//		cout << "*" << length << endl;
		int res=0;
		int counter=0;
		for(int i=0; i<length-1; i+=2){
			res = max(res, current[i]+current[i+1]);
			next[counter++] = current[i]+current[i+1];
		}
		
		for(int i=0; i<counter; ++i)
			current[i] = next[i];
		if(length % 2)
			current[counter] = current[length-1];
		length = (length+1)/2;
		result += res;
	}
	return result;
}

int main(){
	int t;
	scanf("%d", &t);
	
	for(int i=0; i<t; ++i){
		scanf("%d", &n);
		for(int j=0; j<n; ++j){
			scanf("%d", a+j);
		}
		cout << group() << endl;
	}
	
	return 0;
}
