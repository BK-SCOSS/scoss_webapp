#include <stdio.h>
int main(){
	int T;
	scanf("%d",T);
	int arr1, arr2, rs[T];
	for(int i=0;i<T;i++){
		scanf("%d %d ",&arr1, &arr2);
		rs[i] = arr1 + arr2;
	}
	for(int i=0; i<T;i++){
		printf("%d\n",rs[i]);
	}
	return 0;
}
