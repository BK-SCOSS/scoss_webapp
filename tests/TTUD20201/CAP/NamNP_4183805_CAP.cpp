

#include <cstdio>
#include <algorithm>

using namespace std;
//#pragma warning (disable : 4996)

int n,m;
unsigned int A[101];
unsigned int B[101];

int search(int l,int r, unsigned int v) {
	int g = (l+r) / 2;
	if (l >= r) {
		if (B[g] == v) return 1;
		return 0;
	}
	if (B[g] == v) return 1;
	else if (B[g] > v) return search(l, g-1, v);
	else if (B[g] < v) return search(g+1, r, v);
}

int main() {
	int test;
	scanf("%d", &test);
	for (int j = 0; j < test; j++) {
		int cnt = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%u", &A[i]);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%u", &B[i]);
		}
		sort(A, A + n);
		sort(B, B + m);
		for (int i = 0; i < n; i++) {
			if(i == 0){
				if (search(0, m - 1, A[i])) {
						cnt++;
				}
			}else{
			
				if (A[i] != A[i-1] && A[i] <= B[m - 1] && A[i] >= B[0])
				{
					if (search(0, m - 1, A[i])) {
						cnt++;
					}
				}
				else if (A[i] > B[m - 1]) break;
			}
			
		}
		printf("%d\n", cnt);

	}
	return 0;
}



