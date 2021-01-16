#include <bits/stdc++.h>
#define MAX 1000000001

using namespace std;

vector<int> d;
bool save[MAX];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
    	int res = 0;
    	int a, b;
    	cin >> a;
    	int tmp;
    	while(a--){
    		cin >> tmp;
    		save[tmp] = true;
    		d.push_back(tmp);
		}
		cin >> b;
		while(b--){
    		cin >> tmp;
    		if(save[tmp]) res++;
		}
		for(int i = 0; i < d.size(); i++) save[d[i]] = false;
		d.clear();
		cout << res << endl;
	}
	
	return 0;
}
