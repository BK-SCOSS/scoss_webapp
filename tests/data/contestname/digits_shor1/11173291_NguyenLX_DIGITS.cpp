#include<bits/stdc++.h>
using namespace std;

int main() {
	int N; 
	cin >> N;
	int a[N];
	for(int i=0; i<N; i++) {
		cin >> a[i];
		}
	
	int ans[N];
	
	int H, U, S, T, O, I, C;
	for(int j=0; j<N; j++) {
		int count = 0;
		for(int h=1; h<=9; h++) {
			H = h;
			for(int u=0; u<=9; u++) {
				U = u;
				for(int s=1; s<=9; s++) {
				    S = s;
				    for(int t=0; t<=9; t++) {
				        T = t;
				        for(int o=0; o<=9; o++) {
			     			O = o;
			     			for(int i=0; i<=9; i++) {
								I = i;
								for(int c=0; c<=9; c++) {
									C = c;
									if(((H*1000 + U*100 + S*10 + T  +  S*10000 + O*1000 + I*100 + C*10 + T) == a[j])
									&&(H!=U)&&(H!=S)&&(H!=T)&&(H!=O)&&(H!=I)&&(H!=C)
									&&(U!=S)&&(U!=T)&&(U!=O)&&(U!=I)&&(U!=C)
									&&(S!=T)&&(S!=O)&&(S!=I)&&(S!=C)
									&&(T!=O)&&(T!=I)&&(T!=C)
									&&(O!=I)&&(O!=C)
									&&(I!=C)) {
										count++;
										}
									}
								}
							}
				        }
				    }
				}
			}
			ans[j] = count;
		}
		for(int i=0; i<N; i++){
			cout << ans[i] << endl;
			}
		
}
