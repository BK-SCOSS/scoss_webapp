#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	int seg=n;
	cin >> t;
	while(t>0){
		cin >> n;
		vector<int> a;
		int rs=0;
		for(int i=0;i<n;i++) {
			int tmp; cin >> tmp;
			a.push_back(tmp);
		}
		
		while(a.size()!=1){
			vector<int> tg;
			for(int temp: a){ 
//			cout << temp << " ";
			tg.push_back(temp)	;
			}
				a.clear(); int max=0;
		for(int i=0;i<tg.size();i=i+2){
			if(i==tg.size()-1&&i%2==0){
				a.push_back(tg[i]);
				if(max>tg[i]) max=tg[i];
			}
			else
			a.push_back(tg[i]+tg[i+1]);
							if(max>tg[i]+tg[i+1]) max=tg[i]+tg[i+1];

		}
		
		for(int tmp: a){
			if(max< tmp) max= tmp;
		}
		rs+=max;
	}
		cout << rs;
		t--;
	}
	
}
