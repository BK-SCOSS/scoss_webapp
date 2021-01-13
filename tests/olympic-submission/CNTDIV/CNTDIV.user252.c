#include <stdio.h>

int demUoc(int n){
	unsigned long long t = n * (n + 1) * (n + 2);
	unsigned long long t2 = t * t;
	int count = 0;
	unsigned long long i;
	for(i = 1; i < t; i++) {
		if(t2 % i == 0 && t % i != 0)
			count++;
	}
	return count;
}
int main() {
	int arr[1000000];
	int n;
	scanf("%d", &n);
	int m, i = 0;
	for(i = 0; i < n; i++){
		scanf("%d", &m);
		arr[i] = demUoc(m);
	}
	for(i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
}
