#include<bits/stdc++.h>
using namespace std;

int T;
int n, m;
int const Max = 101;
unsigned long long a[Max];
unsigned long long b[Max];
//int count;
//int c[max][max];  // c[i][j] la so phan tu giao nhau tu dau dden a[i] va b[j]


void input(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	cin >> m;
	for(int i=1; i<=m; i++){
		cin >> b[i];
	}
//	count = 0;
}

//void init_dp(){
//	// khoi tao
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=m; j++){
//			c[i][j] = 0;
//		}
//	}	
//}

int main(){
	cin >> T;
	while(T != 0){
		T = T-1;
		set<unsigned long long> s;
		int count = 0;
		input();
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(a[i] == b[j]){
//					count += 1;
//					break;
					s.insert(a[i]);
				}
			}
		}
		cout << s.size();
		
		
	}
	return 0;
}
