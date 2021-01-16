#include <bits/stdc++.h>
using namespace std;

#define ll long long 
vector<ll> A;
ll testcase, N;


int lis() 
{ 
	int *lis, i, j, max = 0; 
	lis = (int*)malloc(sizeof(int) * N); 

	/* Initialize LIS values for all indexes */
	for (i = 0; i < N; i++) 
		lis[i] = 1; 

	/* Compute optimized LIS values in bottom up manner */
	for (i = 1; i < N; i++) 
		for (j = 0; j < i; j++) 
			if (A[i] - A[j]  == 1 && lis[i] < lis[j] + 1) 
				lis[i] = lis[j] + 1; 

	/* Pick maximum of all LIS values */
	for (i = 0; i < N; i++) 
		if (max < lis[i]) 
			max = lis[i]; 

	/* Free memory to avoid memory leak */
	free(lis); 

	return max; 
} 


int main(){
    cin >> testcase;
    while(testcase--){
    cin >> N;
    ll tmp;
    for(int i=0; i < N; i++){
        cin >> tmp;
        A.push_back(tmp);
    }
    cout << lis() << endl;
    }



}