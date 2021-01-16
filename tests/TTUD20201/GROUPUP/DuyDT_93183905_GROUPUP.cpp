#include <bits/stdc++.h>

using namespace std;

vector<int> d;
vector<int> d1;


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	int tmp;
    	for(int i = 0; i < n; i++){
    		cin >> tmp;
    		d.push_back(tmp);
		}
		int res = 0;
		bool flag = true;
		while(1){
			int m = 0;
			if(flag){
				if(d.size() == 1) break;
				for(int i = 0; i < d.size(); i += 2){
					tmp = d[i];
					if(i < d.size() - 1) tmp += d[i + 1];
					d1.push_back(tmp);
					if(tmp > m) m = tmp;
				}
				
				d.clear();
			}else{
				if(d1.size() == 1) break;
				for(int i = 0; i < d1.size(); i += 2){
					tmp = d1[i];
					if(i < d1.size() - 1) tmp += d1[i + 1];
					d.push_back(tmp);
					if(tmp > m) m = tmp;
				}
				
				d1.clear();
			}
			flag = 1 - flag;
			res += m;
		}
		cout << res << endl;
		
		d.clear();
	}
    
	
	return 0;
}
