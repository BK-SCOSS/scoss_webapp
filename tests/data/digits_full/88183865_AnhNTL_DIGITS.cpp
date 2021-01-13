#include <bits/stdc++.h>

using namespace std;

int test;
int a[10];
int n;

bool check(int a[]) {
	int cnt=0;
	for(int i=1; i<=6; i++) {
		for(int j=1; j<=7; j++) {
			if(i!=j && a[i] == a[j]){
				cnt++;
			}
		}
	}
	if(cnt == 0) return true;
	else return false;
}

int main() {
	cin >> test;
	for(int i=0; i<test; i++){
	cin >> n;
	int A = 0;
	for(int i=0; i<10; i++){
		a[10] =-1;
	}
	for(int h=1; h<10; h++) {
		a[1] = h;
		for(int u=0; u<10; u++){
			a[2] = u;
			for(int s=1; s<10; s++){
				a[3] = s;
				for(int t=0; t<10; t++){
					a[4] = t;
					for(int o=0; o<10; o++){
						a[5]=o;
						for(int i=0; i<10; i++) {
							a[6]=i;
							for(int c=0; c<10; c++){
								a[7]=c;
								if(check(a) && (1000*h+100*u+10*s+t+10000*s+1000*o+100*i+10*c+t == n)) A++;
							}
						}
					}
				}
			}
		}
	}
	cout << A;
}
}
