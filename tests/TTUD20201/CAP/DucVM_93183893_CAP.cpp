#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[101], b[101];
int T;
map<int,int> mem;
vector<int> result;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    for(int i = 0; i<T; i++){
    	int rs = 0;
    	cin >> n;
    	for(int j = 0; j<n; j++){
    		cin >> a[j];
    		mem[a[j]] = 1;
		}
		cin >> m; 
		for(int j = 0; j<m; j++){
			cin >> b[j];
			if(mem[b[j]]) rs++;
		}
		result.push_back(rs);
		mem.clear();
	}
	
	for(int i = 0; i<T; i++){
		cout << result[i] << "\n";
	}
	
	return 0;
}

