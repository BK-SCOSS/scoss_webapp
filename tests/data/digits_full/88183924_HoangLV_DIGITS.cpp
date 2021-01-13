#include<bits/stdc++.h>

using namespace std;


int main(){
	int n, ans =0, test, tmp = 0;
	int T[51];
	cin >> test;
	
	for(int i =0; i< test; i++){
		cin >> T[i];
	}
	
	while(tmp < test){
	
	for(int h= 1; h<= 9; h++){
		for(int u =0; u<=9; u++){
			
			if(u == h ) continue;
			
			for(int s =1; s<= 9; s++){
				
				if(s == u || s == h) continue;
				
				for(int t = 0; t<= 9; t++){
					
					if(t == s|| t == u || t== h) continue;
					
					for(int o = 0; o<= 9; o++){
						
						if(o == t || o == s || o == u || o == h) continue;
						
						for(int i = 0 ; i<= 9; i++){
							
							if(i == o || i== t || i== s || i==u || i==h) continue;
							
							for(int c =0; c <=9; c++){
								
								if(c == i || c == o || c == t || c== s || c==u || c == h) continue;
								
								int sum = s*10000+ (h+ o)*1000 + (u+i)* 100+ (s+c)*10+ 2*t;
								
								if(sum == T[tmp]) ans++;
							}
						}
					}
				}
			}
		}
	}
	
	T[tmp] = ans;
	ans = 0;
	tmp++;
	
  }
  
  
	for(int i =0; i< test; i++){
		cout << T[i] << endl;
	}

}
