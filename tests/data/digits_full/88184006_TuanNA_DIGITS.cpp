#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		int h, u, s, t, o, i, c;
		int temp = 0;
		
		cin >> n;
		
		for(h = 1; h <= 9; h++){
			for(s = 1; s <= 9; s++){
				for(u = 0; u <= 9; u++){
					for(o = 0; o <= 9; o++){
						for(i = 0; i <= 9; i++){
							for(c = 0; c <= 9; c++){
								for(t = 0; t <= 9; t++){
									if((h*1000+u*100+s*10+t+s*10000+o*1000+i*100+c*10+t) == n &&
										h!=u && h!=s && h!=t && h!=o && h!=i && h!=c
										&& u!=s && u!=t && u!=i && u!=o && u!=c &&
										s!=t && s!=o && s!=i && s!=c && t!=o && t!=i && t!=c &&
										o!=i && o!=c && i!=c){
										temp++;
									}	
								}
							}
						}
					}
				}
			}
		}
		
		cout << temp << endl;
	}
	return 0;
}
