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

int calculate(int result, int A[], int n){
	if(n == 1) return result;
	else if(n % 2 == 0){
		int m = (n+1)/2;
		int j = 0;
		for(int i = 0; i < m; i++){
			A[i] = A[j] + A[j+1];
			j+=2;
		}
		result += maxInArr(A, m);
		return calculate(result, A, m);
	}
	else{
		int m = (n+1)/2;
		int j = 0;
		for(int i = 0; i < m; i++){
			A[i] = A[j] + A[j+1];
			j+=2;
		}
		A[m-1] = A[n-1];
		result += maxInArr(A, m);
		return calculate(result, A, m);
	}
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
		
		int temp = 0;
		int result = calculate(temp, A, n);
		
		cout << result << endl;
		
	}
	
	return 0;
}
