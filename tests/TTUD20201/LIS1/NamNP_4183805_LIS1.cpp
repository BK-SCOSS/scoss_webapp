

#include <cstdio>
#include <algorithm>
#include <vector>
//#pragma warning(disable : 4996)

using namespace std;

int n;
unsigned int A[100000];
int B[100000];
int main() {
	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		scanf("%d", &n);
		
		for (int j = 0; j < n; j++) {
			scanf("%u", &A[j]);
		}
		int s = 1;
		for(int j = n-1; j >= 0; j--){
			
			B[j] = 1;
			int tmp = A[j] + 1;
			
			for(int k = j + 1; k < n; k++){
				if (A[k] == tmp) {	
					B[j] += B[k];
					break;
				}
			}
			
			s = B[j] > s ? B[j] : s;
		}
		printf("%d\n", s);

	}

	return 0;
}

