#include<iostream>
#include<list>
using namespace std;
int n, T, a;

int main(){
	cin >> T;
	
	while(T--){
		int time =0;
		list<int> t;
		cin >> n;
		for(int i=1;i<=n;i++) {
			cin >> a;
			t.push_back(a);

		}
		while(t.size() != 1){
			list<int> tg;
			int timemax=0;
			int add =0;
			if(t.size() %2 == 0){
				int dem=0;
				
				for(int k: t){
					add += k;
					dem++;
					if(dem==2) {
						tg.push_back(add);
						if(timemax <add) timemax = add;
						dem=0;
						add =0;
					}
				}
			} else{
				int dem=0;

				int k;
				for(int k: t){

						add +=k;
						dem++;
						if(dem==2){
							tg.push_back(add);
							if(timemax < add) timemax = add;
							dem=0;
							add=0;
						}
					
				}
				tg.push_back(t.back());
			}
			
			time += timemax;
			t = tg;
		}
		
		cout << time << endl;
		
	}
	
	
	
}
