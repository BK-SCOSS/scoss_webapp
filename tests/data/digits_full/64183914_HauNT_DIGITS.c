#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int bit[10] = {0};
int sum, count, n;
int hs[7] = {0};


void solve(int cur) {
	int i;

	if(bit[0] == 0) {
		if(cur != 0 && cur != 2) {
			sum = sum + hs[cur]*0;
			bit[0] = 1;

			if(sum <= n) {
				if(cur == 6) {
					if(sum == n) {
						count++;
					}
				}
				else {
					solve(cur + 1);
				}
			}
			

			bit[0] = 0;
			sum = sum - hs[cur]*0;
		}
	}

	for(i = 1; i <= 9; i++) {
		if(bit[i] == 0) {
			bit[i] = 1;
			sum = sum + hs[cur]*i;

			if(sum <= n) {
				if(cur == 6) {
					if(sum == n) {
						count++;
					}
				}
				else {
					solve(cur + 1); 
				}
			}
			

			bit[i] = 0;
			sum = sum - hs[cur]*i;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);

	hs[0] = 1000;
	hs[1] = 100;
	hs[2] = 10010;
	hs[3] = 2;
	hs[4] = 1000;
	hs[5] = 100;
	hs[6] = 10;

	while(T--) {
		scanf("%d", &n);

		count = 0;
		solve(0);

		printf("%d\n", count);
	}
	
	return 0;
}
