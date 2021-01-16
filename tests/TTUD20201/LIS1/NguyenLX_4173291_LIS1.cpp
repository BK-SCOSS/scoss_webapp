#include <bits/stdc++.h>
#define N 100000

int t;
int n;
int a[N];

void lis() {
	int count;
	int res = 0;
	for(int i=0; i<=n-1; i++) {
		count = 1;
		for(int j=i+1; j<=n-1; j++) {
			if(a[i] == a[j]-1){
				count = count + 1;
				} 
			}
		res = count > res ? count : res;
		}
	printf("%d\n", res);
		
	}
	
int main() {
	scanf("%d\n", &t);
	for(int j=0; j<=t-1; j++) {
		scanf("%d\n", &n);
		for(int i=0; i<=n-1; i++) {
			scanf("%d", &a[i]);
			}
		}
	lis();
	}
