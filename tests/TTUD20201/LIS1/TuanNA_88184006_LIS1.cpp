#include<bits/stdc++.h>
using namespace std;
 
int maxInArr(int A[], int n)
{
	int max = A[0];
	for(int i = 1; i < n; i++)
	{
		if(max < A[i])
			max = A[i];
	}
	return max;
}
 
int LIS(int M[], int n)
{
	int L[n];
	L[0] = 1;
	for(int i = 1; i < n; i++){
		L[i] = 1;
		for(int j = i - 1; j >= 0; j--){
			if(L[i] < L[j] + 1 && M[i] == M[j] + 1){
				L[i] = L[j] + 1;
				break;				
			}
		}
	}
	int max = maxInArr(L, n);
	return max;
}
 
int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int A[n];
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}

		int result = LIS(A, n);
		cout << result << endl;
	}
	return 0;
}
