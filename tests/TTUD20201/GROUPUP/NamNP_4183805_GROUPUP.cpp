
#include <cstdio>

//#pragma warning(disable : 4996)
using namespace std;

int n;
int A[100000];


int main() {
	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++)scanf("%d", &A[j]);

		int flag = 1;
		int time = 0;
		if (n == 1) {
			printf("0\n");
			continue;
		}
		do {
			int tmp = 0;
			int index = 0;
			for (int k = 0; k < n; k = k + 2) {
				if (k + 1 < n) {
					A[index] = A[k] + A[k + 1];
					tmp = A[index] > tmp ? A[index] : tmp;
				}
				if (n % 2 == 1 && k == n-1) {
					A[index] = A[k];
				}
				index++;
			}
			n = (n+1) / 2;
			time += tmp;
			if (n == 1)break;
			

		} while (flag);
		printf("%d\n", time);
	}


	return 0;
}
