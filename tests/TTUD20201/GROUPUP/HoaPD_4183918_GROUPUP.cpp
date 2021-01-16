#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int t;
int n;
int tg;
int max_t;
queue< int > a;

void test(){
	int x = a.size();
	while( x > 1){
		int tmp1 = a.front();
		a.pop();
		int tmp2 = a.front();
		a.pop();
		max_t = max(max_t, tmp1+ tmp2);
		a.push(tmp1+tmp2);
		x-=2; 
	}
	if(x == 1){
		a.push(a.front());
		a.pop();
	}
	
}

int main(int argc, char** argv) {
	cin >> t;
	for(int i = 0; i< t; i++){
		queue<int > b;
		a.swap(b);
		tg = 0;
		int tmp;
		cin >> n;
		for(int j =1; j<=n; j++){
			cin >> tmp;
			a.push(tmp);
		}
		
		while(a.size() != 1){
			max_t = 0;
			test();
			tg += max_t;
		}
		cout << tg;
		
	}
}