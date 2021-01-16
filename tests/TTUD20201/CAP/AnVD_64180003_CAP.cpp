#include<bits/stdc++.h>
using namespace std;

set <int> a, b;
int t, n, m, temp;

int main(){
	scanf("%d", &t);
	
	vector <int> result;
	for(int i=0; i<t; ++i){
		a.clear();
		b.clear();
		int res=0;
		scanf("%d", &n);
		for(int i=0; i<n; ++i){
			scanf("%d", &temp);
			a.insert(temp);
		}
		scanf("%d", &m);
		for(int i=0; i<m; ++i){
			scanf("%d", &temp);
			b.insert(temp);
			
		}
		for(auto i: a){
			if(b.find(i) != b.end()){
				++res;
			}
		}
		result.push_back(res);
	}
	
	for(int i=0; i<t; ++i){
		cout << result[i] << endl;
	}
	
	return 0;
}
